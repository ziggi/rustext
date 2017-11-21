/*
	About: rustext natives
	Author: ziggi
*/

#include <sdk/plugin.h>
#include <sdk/amx/amx2.h>
#include <string>
#include "natives.hpp"
#include "common.hpp"
#include "converter.hpp"
#include "russifier.hpp"

extern logprintf_t logprintf;

// native GetRussifierVersion(version[], const size = sizeof(version));
cell AMX_NATIVE_CALL Natives::GetRussifierVersion(AMX *amx, cell *params)
{
	CHECK_PARAMS(2, "GetRussifierVersion");

	amx_SetCString(amx, params[1], PLUGIN_VERSION, params[2]);
	return 1;
}

// native GetRussifierText(RussifierType:type, string[], string_return[], const size = sizeof(string_return));
cell AMX_NATIVE_CALL Natives::GetRussifierText(AMX *amx, cell *params)
{
	CHECK_PARAMS(4, "GetRussifierText");

	char *string;
	cell *dest_addr;

	int type = static_cast<int>(params[1]);
	uint32_t length = amx_GetCString(amx, params[2], string);
	amx_GetAddr(amx, params[3], &dest_addr);
	int size = static_cast<int>(params[4]);

	if (type < 0 || type >= Converter::TypesCount) {
		return 0;
	}

	Converter::Process(string, length, static_cast<Converter::Types>(type));

	amx_SetString(dest_addr, string, 0, 0, size);
	return 1;
}

// native SetPlayerRussifierType(playerid, RussifierType:type);
cell AMX_NATIVE_CALL Natives::SetPlayerRussifierType(AMX *amx, cell *params)
{
	CHECK_PARAMS(2, "SetPlayerRussifierType");

	int playerid = static_cast<int>(params[1]);
	int type = static_cast<int>(params[2]);

	if (playerid < 0 || playerid >= MAX_PLAYERS) {
		return 0;
	}

	if (type == -1) {
		Russifier::DisablePlayer(playerid);
		return 1;
	}

	if (type < 0 || type >= Converter::TypesCount) {
		return 0;
	}

	Russifier::SetPlayerType(playerid, type);
	return 1;
}

// native RussifierType:GetPlayerRussifierType(playerid);
cell AMX_NATIVE_CALL Natives::GetPlayerRussifierType(AMX *amx, cell *params)
{
	CHECK_PARAMS(1, "GetPlayerRussifierType");

	int playerid = static_cast<int>(params[1]);

	if (playerid < 0 || playerid >= MAX_PLAYERS) {
		return 0;
	}

	if (!Russifier::IsPlayerEnabled(playerid)) {
		return -1;
	}

	return Russifier::GetPlayerType(playerid);
}

// native SetDefaultRussifierType(RussifierType:type);
cell AMX_NATIVE_CALL Natives::SetDefaultRussifierType(AMX *amx, cell *params)
{
	CHECK_PARAMS(1, "SetDefaultRussifierType");

	int type = static_cast<int>(params[1]);

	if (type == -1) {
		Russifier::DisableDefault();
		return 1;
	}

	if (type < 0 || type >= Converter::TypesCount) {
		return 0;
	}

	Russifier::SetDefaultType(type);
	return 1;
}

// native RussifierType:GetDefaultRussifierType();
cell AMX_NATIVE_CALL Natives::GetDefaultRussifierType(AMX *amx, cell *params)
{
	CHECK_PARAMS(0, "GetDefaultRussifierType");

	if (!Russifier::IsDefaultEnabled()) {
		return -1;
	}

	return Russifier::GetDefaultType();
}
