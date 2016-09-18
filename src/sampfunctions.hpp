/*
	About: rustext sampfunctions
	Author: ziggi
*/

#ifndef SAMPFUNCTIONS_H
#define SAMPFUNCTIONS_H

#include "common.hpp"

class Samp {
public:
	static int GameTextForAll(const char *string, int time, int style);
	static int GameTextForPlayer(int playerid, const char *string, int time, int style);

	static int TextDrawCreate(float x, float y, const char *text);
	static int TextDrawSetString(int text, const char *string);

	static int CreatePlayerTextDraw(int playerid, float x, float y, const char *text);
	static int PlayerTextDrawSetString(int playerid, int text, const char *string);

	static int CreateMenu(const char *title, int columns, float x, float y, float col1width, float col2width);
	static int AddMenuItem(int menuid, int column, const char *title);
	static int SetMenuColumnHeader(int menuid, int column, const char *text);

	static amx_Function_t addr_GameTextForAll;
	static amx_Function_t addr_GameTextForPlayer;
	static amx_Function_t addr_TextDrawCreate;
	static amx_Function_t addr_TextDrawSetString;
	static amx_Function_t addr_CreatePlayerTextDraw;
	static amx_Function_t addr_PlayerTextDrawSetString;
	static amx_Function_t addr_CreateMenu;
	static amx_Function_t addr_AddMenuItem;
	static amx_Function_t addr_SetMenuColumnHeader;
};

#endif
