/*
	About: rustext hooks
	Author: ziggi
*/

#include <urmem.hpp>
#include "common.hpp"
#include "hooks.hpp"

extern GetRakServerInterface_t GetRakServerInterface;

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

	if (uniqueID && bitStream && *uniqueID == RPC_ShowTextDraw) {
		auto read_offset = bitStream->GetReadOffset();
		auto write_offset = bitStream->GetWriteOffset();

		int player_id = GetIndexFromPlayerID(playerId);

		uint16_t textDrawID;
		_CTextdraw *textDraw = new _CTextdraw;
		uint16_t textLen;
		char text[MAX_TEXT_DRAW_LINE];

		RakNet::BitStream bStream;
		bitStream->Read(textDrawID);
		bitStream->Read(reinterpret_cast<char *>(textDraw), sizeof(_CTextdraw));
		bitStream->Read(textLen);
		bitStream->Read(text, textLen);

		// if (!Callbacks::OnServerSendRPC(GetIndexFromPlayerID(playerId), *uniqueID, bitStream))
			// return false;

		bitStream->SetReadOffset(read_offset);
		bitStream->SetWriteOffset(write_offset);
	}

	return urmem::call_function<urmem::calling_convention::thiscall, bool>(
		_addr_rpc, _this, uniqueID, bitStream, priority, reliability,
		orderingChannel, playerId, broadcast, shiftTimestamp);
}

int Hooks::GetIndexFromPlayerID(const PlayerID &id)
{
	return urmem::call_function<urmem::calling_convention::thiscall, int>(
		_addr_get_index_from_playerid, _addr_rakserver, id);
}
