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

extern logprintf_t logprintf;

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

	Converter::Process(string);
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

	Converter::Process(string);
	return Samp::GameTextForPlayer(playerid, string.c_str(), time, style);
}

// TextDrawCreate(Float:x, Float:y, text[]);
cell AMX_NATIVE_CALL Natives::TextDrawCreate(AMX *amx, cell *params)
{
	CHECK_PARAMS(3, "TextDrawCreate");

	float x = static_cast<float>(params[1]);
	float y = static_cast<float>(params[2]);
	std::string string = amx_GetCppString(amx, params[3]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	Converter::Process(string);
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

	Converter::Process(string);
	return Samp::TextDrawSetString(text, string.c_str());
}

// CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]);
cell AMX_NATIVE_CALL Natives::CreatePlayerTextDraw(AMX *amx, cell *params)
{
	CHECK_PARAMS(4, "CreatePlayerTextDraw");

	int playerid = static_cast<int>(params[1]);
	float x = static_cast<float>(params[2]);
	float y = static_cast<float>(params[3]);
	std::string string = amx_GetCppString(amx, params[4]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	Converter::Process(string);
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

	Converter::Process(string);
	return Samp::PlayerTextDrawSetString(playerid, textid, string.c_str());
}

// CreateMenu(title[], columns, Float:x, Float:y, Float:col1width, Float:col2width);
cell AMX_NATIVE_CALL Natives::CreateMenu(AMX *amx, cell *params)
{
	CHECK_PARAMS(6, "CreateMenu");

	std::string string = amx_GetCppString(amx, params[1]);
	int columns = static_cast<int>(params[2]);
	float x = static_cast<float>(params[3]);
	float y = static_cast<float>(params[4]);
	float col1width = static_cast<float>(params[5]);
	float col2width = static_cast<float>(params[6]);

	int length = string.length();
	if (length == 0) {
		return 0;
	}

	Converter::Process(string);
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

	Converter::Process(string);
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

	Converter::Process(string);
	return Samp::SetMenuColumnHeader(menuid, column, string.c_str());
}