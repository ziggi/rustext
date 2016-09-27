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

extern logprintf_t logprintf;

// native SetPlayerRussifierType(playerid, RussifierType:type);
cell AMX_NATIVE_CALL Natives::SetPlayerRussifierType(AMX *amx, cell *params)
{
	CHECK_PARAMS(2, "SetPlayerRussifierType");

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
	CHECK_PARAMS(1, "GetPlayerRussifierType");

	int playerid = static_cast<int>(params[1]);

	if (playerid < 0 || playerid > MAX_PLAYERS) {
		return 0;
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

	return Russifier::GetDefaultType();
}

// native GameTextForAll(const string[], time, style);
cell AMX_NATIVE_CALL Natives::GameTextForAll(AMX *amx, cell *params)
{
	CHECK_PARAMS(3, "GameTextForAll");

	std::string string = amx_GetCppString(amx, params[1]);
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

// native GameTextForPlayer(playerid, const string[], time, style);
cell AMX_NATIVE_CALL Natives::GameTextForPlayer(AMX *amx, cell *params)
{
	CHECK_PARAMS(4, "GameTextForPlayer");

	int playerid = static_cast<int>(params[1]);
	std::string string = amx_GetCppString(amx, params[2]);
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

// TextDrawCreate(Float:x, Float:y, text[]);
cell AMX_NATIVE_CALL Natives::TextDrawCreate(AMX *amx, cell *params)
{
	CHECK_PARAMS(3, "TextDrawCreate");

	float x = amx_ctof(params[1]);
	float y = amx_ctof(params[2]);
	std::string string = amx_GetCppString(amx, params[3]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::TextDrawCreate(x, y, string.c_str());
}

// TextDrawSetString(Text:text, string[]);
cell AMX_NATIVE_CALL Natives::TextDrawSetString(AMX *amx, cell *params)
{
	CHECK_PARAMS(2, "TextDrawSetString");

	int text = static_cast<int>(params[1]);
	std::string string = amx_GetCppString(amx, params[2]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::TextDrawSetString(text, string.c_str());
}

// CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]);
cell AMX_NATIVE_CALL Natives::CreatePlayerTextDraw(AMX *amx, cell *params)
{
	CHECK_PARAMS(4, "CreatePlayerTextDraw");

	int playerid = static_cast<int>(params[1]);
	float x = amx_ctof(params[2]);
	float y = amx_ctof(params[3]);
	std::string string = amx_GetCppString(amx, params[4]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsPlayerEnabled(playerid) || Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetPlayerType(playerid));
	}

	return Samp::CreatePlayerTextDraw(playerid, x, y, string.c_str());
}

// PlayerTextDrawSetString(playerid, PlayerText:text, string[]);
cell AMX_NATIVE_CALL Natives::PlayerTextDrawSetString(AMX *amx, cell *params)
{
	CHECK_PARAMS(3, "PlayerTextDrawSetString");

	int playerid = static_cast<int>(params[1]);
	int textid = static_cast<int>(params[2]);
	std::string string = amx_GetCppString(amx, params[3]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsPlayerEnabled(playerid) || Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetPlayerType(playerid));
	}

	return Samp::PlayerTextDrawSetString(playerid, textid, string.c_str());
}

// CreateMenu(title[], columns, Float:x, Float:y, Float:col1width, Float:col2width);
cell AMX_NATIVE_CALL Natives::CreateMenu(AMX *amx, cell *params)
{
	CHECK_PARAMS(6, "CreateMenu");

	std::string string = amx_GetCppString(amx, params[1]);
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

// AddMenuItem(Menu:menuid, column, title[]);
cell AMX_NATIVE_CALL Natives::AddMenuItem(AMX *amx, cell *params)
{
	CHECK_PARAMS(3, "AddMenuItem");

	int menuid = static_cast<int>(params[1]);
	int column = static_cast<int>(params[2]);
	std::string string = amx_GetCppString(amx, params[3]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::AddMenuItem(menuid, column, string.c_str());
}

// SetMenuColumnHeader(menuid, column, text[]);
cell AMX_NATIVE_CALL Natives::SetMenuColumnHeader(AMX *amx, cell *params)
{
	CHECK_PARAMS(3, "SetMenuColumnHeader");

	int menuid = static_cast<int>(params[1]);
	int column = static_cast<int>(params[2]);
	std::string string = amx_GetCppString(amx, params[3]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	if (Russifier::IsDefaultEnabled()) {
		Converter::Process(string, Russifier::GetDefaultType());
	}

	return Samp::SetMenuColumnHeader(menuid, column, string.c_str());
}
