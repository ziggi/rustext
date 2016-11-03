/*
	About: rustext hooks
	Author: ziggi
*/

#include <urmem.hpp>
#include "common.hpp"
#include "hooks.hpp"
#include "russifier.hpp"

#if _WIN32
	#pragma warning(disable: 4996)
#endif

extern GetRakServerInterface_t GetRakServerInterface;

std::shared_ptr<urmem::hook>
	Hooks::_hook_get_rak_server_interface,
	Hooks::_hook_rakserver__rpc;

urmem::address_t
	Hooks::_addr_rakserver,
	Hooks::_addr_rpc,
	Hooks::_addr_get_index_from_playerid;

bool Hooks::Init(void)
{
	urmem::sig_scanner scanner;
	urmem::address_t addr{};

	addr = urmem::get_func_addr(GetRakServerInterface);
	if (scanner.init(addr)) {
		_hook_get_rak_server_interface = std::make_shared<urmem::hook>(addr, urmem::get_func_addr(&HOOK_GetRakServerInterface));
		return true;
	}

	return false;
}

void *Hooks::HOOK_GetRakServerInterface(void)
{
	urmem::hook::raii scope(*_hook_get_rak_server_interface);

	auto rakserver = urmem::call_function<urmem::calling_convention::cdeclcall, void *>(
		_hook_get_rak_server_interface->get_original_addr());

	if (auto vmt = urmem::pointer(rakserver).field<urmem::address_t *>(0)) {
		_addr_rakserver = reinterpret_cast<urmem::address_t>(rakserver);
#ifdef _WIN32
		_addr_rpc = vmt[32];
		_addr_get_index_from_playerid = vmt[57];
#else
		_addr_rpc = vmt[35];
		_addr_get_index_from_playerid = vmt[58];
#endif
		_hook_rakserver__rpc = std::make_shared<urmem::hook>(
			_addr_rpc,
			urmem::get_func_addr(&HOOK_RakServer__RPC));
	}

	return rakserver;
}

bool THISCALL Hooks::HOOK_RakServer__RPC(void *_this, RPCIndex *uniqueID, RakNet::BitStream *bitStream, int priority,
	int reliability, char orderingChannel, PlayerID playerId, bool broadcast, bool shiftTimestamp)
{
	urmem::hook::raii scope(*_hook_rakserver__rpc);

	// validate rpc parameters
	if (!uniqueID || !bitStream) {
		return RPC(_this, uniqueID, bitStream, priority, reliability,
			orderingChannel, playerId, broadcast, shiftTimestamp);
	}

	if (*uniqueID != RPC_DisplayGameText &&
		*uniqueID != RPC_InitMenu &&
		*uniqueID != RPC_ShowTextDraw) {
		return RPC(_this, uniqueID, bitStream, priority, reliability,
			orderingChannel, playerId, broadcast, shiftTimestamp);
	}

	// remember default offsets
	auto read_offset = bitStream->GetReadOffset();
	auto write_offset = bitStream->GetWriteOffset();

	// check on player valid
	int player_id = GetIndexFromPlayerID(playerId);
	if (player_id == -1 || !Russifier::IsEnabledForPlayer(player_id)) {
		return RPC(_this, uniqueID, bitStream, priority, reliability,
			orderingChannel, playerId, broadcast, shiftTimestamp);
	}

	if (*uniqueID == RPC_DisplayGameText) {
		// skip textdraw id and data
		bitStream->SetReadOffset(32 + 32);

		// read text
		uint32_t textLen;
		bitStream->Read(textLen);

		char *text = new char[textLen];
		bitStream->Read(text, textLen);

		// convert
		Converter::Process(text, Russifier::GetPlayerType(player_id));

		// write converted text
		bitStream->SetWriteOffset(32 + 32 + 32);
		bitStream->Write(text, textLen);

		delete [] text;
	} else if (*uniqueID == RPC_InitMenu) {
		const int MAX_MENU_TEXT_SIZE = 32;
		const int MAX_ITEMS = 12;
		const int MAX_COLUMNS = 2;

		int offsetToHeader;
		uint32_t isTwoColumns;
		char title[MAX_MENU_TEXT_SIZE];
		uint8_t	itemsCount[MAX_COLUMNS];
		char items[MAX_ITEMS][MAX_COLUMNS][MAX_MENU_TEXT_SIZE];
		char headers[MAX_COLUMNS][MAX_MENU_TEXT_SIZE];

		// skip menu id
		bitStream->SetReadOffset(8);

		// read text
		bitStream->Read(isTwoColumns);
		bitStream->Read(title, MAX_MENU_TEXT_SIZE);

		// skip menu id, text, pos, width
		offsetToHeader = 8 + 32 + MAX_MENU_TEXT_SIZE + 32 + 32 + 32;
		if (isTwoColumns) {
			offsetToHeader += 32;
		}
		// skip interaction
		offsetToHeader += 32 + MAX_ITEMS * 32;
		bitStream->SetReadOffset(offsetToHeader);

		// read headers and items
		for (uint8_t i = 0; i < isTwoColumns + 1; i++) {
			bitStream->Read(headers[i], MAX_MENU_TEXT_SIZE);
			bitStream->Read(itemsCount[i]);

			for (uint8_t j = 0; j < itemsCount[j]; j++) {
				bitStream->Read(items[j][i], MAX_MENU_TEXT_SIZE);
			}
		}

		// convert
		Converter::Types playerRussifierType = Russifier::GetPlayerType(player_id);

		Converter::Process(title, playerRussifierType);

		for (uint8_t i = 0; i < isTwoColumns + 1; i++) {
			Converter::Process(headers[i], playerRussifierType);

			for (uint8_t j = 0; j < itemsCount[j]; j++) {
				Converter::Process(items[j][i], playerRussifierType);
			}
		}

		// set write offsets: skip menu id and columns status
		bitStream->SetWriteOffset(8 + 32);
		// write converted text
		bitStream->Write(title);

		// skip menu id, text, pos, width and interaction
		bitStream->SetWriteOffset(offsetToHeader);
		// write converted headers and items
		for (uint8_t i = 0; i < isTwoColumns + 1; i++) {
			bitStream->Write(headers[i], MAX_MENU_TEXT_SIZE);
			bitStream->Write(itemsCount[i]);

			for (uint8_t j = 0; j < itemsCount[j]; j++) {
				bitStream->Write(items[j][i], MAX_MENU_TEXT_SIZE);
			}
		}
	} else if (*uniqueID == RPC_ShowTextDraw) {
		const int offsetToText = 16 + 63 * 8;

		// skip textdraw id and data
		bitStream->SetReadOffset(offsetToText);

		// read text
		uint16_t textLen;
		bitStream->Read(textLen);

		char *text = new char[textLen];
		bitStream->Read(text, textLen);

		// convert
		Converter::Process(text, Russifier::GetPlayerType(player_id));

		// write converted text
		bitStream->SetWriteOffset(offsetToText + 16);
		bitStream->Write(text, textLen);

		delete [] text;
	}

	// set default offsets
	bitStream->SetReadOffset(read_offset);
	bitStream->SetWriteOffset(write_offset);

	// call hooked function
	return RPC(_this, uniqueID, bitStream, priority, reliability,
		orderingChannel, playerId, broadcast, shiftTimestamp);
}

int Hooks::GetIndexFromPlayerID(const PlayerID &id)
{
	return urmem::call_function<urmem::calling_convention::thiscall, int>(
		_addr_get_index_from_playerid, _addr_rakserver, id);
}

bool Hooks::RPC(void *_this, RPCIndex *uniqueID, RakNet::BitStream *bitStream, int priority,
	int reliability, char orderingChannel, PlayerID playerId, bool broadcast, bool shiftTimestamp)
{
	return urmem::call_function<urmem::calling_convention::thiscall, bool>(
		_addr_rpc, _this, uniqueID, bitStream, priority, reliability,
		orderingChannel, playerId, broadcast, shiftTimestamp);
}
