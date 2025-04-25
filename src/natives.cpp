/*
	About: rustext natives
	Author: ziggi
*/

#include <sdk/plugin.h>
#include <sdk/amx/amx2.h>
#include <string>
#include "natives.hpp"
#include "common.hpp"
#include "sampfunctions.hpp"
#include "converter.hpp"
#include "russifier.hpp"
#include "format.h"

extern logprintf_t logprintf;

// native GetRussifierVersion(version[], const size = sizeof(version));
cell AMX_NATIVE_CALL Natives::GetRussifierVersion(AMX *amx, cell *params)
{
	amx_SetCString(amx, params[1], PLUGIN_VERSION, params[2]);
	return 1;
}

// native GetRussifierText(RussifierType:type, string[], string_return[], const size = sizeof(string_return));
cell AMX_NATIVE_CALL Natives::GetRussifierText(AMX *amx, cell *params)
{
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
	int playerid = static_cast<int>(params[1]);
	int type = static_cast<int>(params[2]);

	if (playerid < 0 || playerid > MAX_PLAYERS) {
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
	int playerid = static_cast<int>(params[1]);

	if (playerid < 0 || playerid > MAX_PLAYERS) {
		return 0;
	}

	return Russifier::GetPlayerType(playerid);
}

// native SetDefaultRussifierType(RussifierType:type);
cell AMX_NATIVE_CALL Natives::SetDefaultRussifierType(AMX *amx, cell *params)
{
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
	return Russifier::GetDefaultType();
}

// native GameTextForAll(const string[], time, style, {Float,_}:...);
cell AMX_NATIVE_CALL Natives::GameTextForAll(AMX *amx, cell *params)
{
	std::string string = format_amxstring(amx, get_amxaddr(amx, params[1]), params, 4);
	int time = static_cast<int>(params[2]);
	int style = static_cast<int>(params[3]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::GameTextForAll(string.c_str(), time, style);
}

// native GameTextForPlayer(playerid, const string[], time, style, {Float,_}:...);
cell AMX_NATIVE_CALL Natives::GameTextForPlayer(AMX *amx, cell *params)
{
	int playerid = static_cast<int>(params[1]);
	std::string string = format_amxstring(amx, get_amxaddr(amx, params[2]), params, 4);
	int time = static_cast<int>(params[3]);
	int style = static_cast<int>(params[4]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsPlayerEnabled(playerid) || Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetPlayerType(playerid));
	}

	return Samp::GameTextForPlayer(playerid, string.c_str(), time, style);
}

// TextDrawCreate(Float:x, Float:y, text[], {Float,_}:...);
cell AMX_NATIVE_CALL Natives::TextDrawCreate(AMX *amx, cell *params)
{
	float x = amx_ctof(params[1]);
	float y = amx_ctof(params[2]);
	std::string string = format_amxstring(amx, get_amxaddr(amx, params[3]), params, 4);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::TextDrawCreate(x, y, string.c_str());
}

// TextDrawSetString(Text:text, string[], {Float,_}:...);
cell AMX_NATIVE_CALL Natives::TextDrawSetString(AMX *amx, cell *params)
{
	int text = static_cast<int>(params[1]);
	std::string string = format_amxstring(amx, get_amxaddr(amx, params[2]), params, 3);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::TextDrawSetString(text, string.c_str());
}

// CreatePlayerTextDraw(playerid, Float:x, Float:y, text[], {Float,_}:...);
cell AMX_NATIVE_CALL Natives::CreatePlayerTextDraw(AMX *amx, cell *params)
{
	int playerid = static_cast<int>(params[1]);
	float x = amx_ctof(params[2]);
	float y = amx_ctof(params[3]);
	std::string string = format_amxstring(amx, get_amxaddr(amx, params[4]), params, 5);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsPlayerEnabled(playerid) || Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetPlayerType(playerid));
	}

	return Samp::CreatePlayerTextDraw(playerid, x, y, string.c_str());
}

// PlayerTextDrawSetString(playerid, PlayerText:text, string[], {Float,_}:...);
cell AMX_NATIVE_CALL Natives::PlayerTextDrawSetString(AMX *amx, cell *params)
{
	int playerid = static_cast<int>(params[1]);
	int textid = static_cast<int>(params[2]);
	std::string string = format_amxstring(amx, get_amxaddr(amx, params[3]), params, 4);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsPlayerEnabled(playerid) || Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetPlayerType(playerid));
	}

	return Samp::PlayerTextDrawSetString(playerid, textid, string.c_str());
}

// CreateMenu(title[], columns, Float:x, Float:y, Float:col1width, Float:col2width, {Float,_}:...);
cell AMX_NATIVE_CALL Natives::CreateMenu(AMX *amx, cell *params)
{
	std::string string = format_amxstring(amx, get_amxaddr(amx, params[1]), params, 7);
	int columns = static_cast<int>(params[2]);
	float x = amx_ctof(params[3]);
	float y = amx_ctof(params[4]);
	float col1width = amx_ctof(params[5]);
	float col2width = amx_ctof(params[6]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::CreateMenu(string.c_str(), columns, x, y, col1width, col2width);
}

// AddMenuItem(Menu:menuid, column, title[], {Float,_}:...);
cell AMX_NATIVE_CALL Natives::AddMenuItem(AMX *amx, cell *params)
{
	int menuid = static_cast<int>(params[1]);
	int column = static_cast<int>(params[2]);
	std::string string = format_amxstring(amx, get_amxaddr(amx, params[3]), params, 4);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::AddMenuItem(menuid, column, string.c_str());
}

// SetMenuColumnHeader(menuid, column, text[], {Float,_}:...);
cell AMX_NATIVE_CALL Natives::SetMenuColumnHeader(AMX *amx, cell *params)
{
	int menuid = static_cast<int>(params[1]);
	int column = static_cast<int>(params[2]);
	std::string string = format_amxstring(amx, get_amxaddr(amx, params[3]), params, 4);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::SetMenuColumnHeader(menuid, column, string.c_str());
}
