/*
	About: rustext sampfunctions
	Author: ziggi
*/

#include <sdk/plugin.h>
#include <cstring>
#include <list>
#include "common.hpp"
#include "sampfunctions.hpp"

extern std::list <AMX *> g_pAmx;
extern logprintf_t logprintf;

int Samp::GameTextForAll(const char *string, int time, int style)
{
	// init
	const int PARAMS = 3;

	cell *addr;
	cell *params = new cell [PARAMS + 1];

	// set the params
	params[0] = PARAMS * sizeof(cell);

	int length = strlen(string);
	amx_Allot(g_pAmx.front(), length + 1, &params[1], &addr);
	amx_SetString(addr, string, 0, 0, length + 1);

	params[2] = time;
	params[3] = style;

	// execute
	int result = addr_GameTextForAll(g_pAmx.front(), params);

	// release
	amx_Release(g_pAmx.front(), params[1]);
	delete [] params;

	return result;
}

int Samp::GameTextForPlayer(int playerid, const char *string, int time, int style)
{
	// init
	const int PARAMS = 4;

	cell *addr;
	cell *params = new cell [PARAMS + 1];

	// set the params
	params[0] = PARAMS * sizeof(cell);
	params[1] = playerid;

	int length = strlen(string);
	amx_Allot(g_pAmx.front(), length + 1, &params[2], &addr);
	amx_SetString(addr, string, 0, 0, length + 1);

	params[3] = time;
	params[4] = style;

	// execute
	int result = addr_GameTextForPlayer(g_pAmx.front(), params);

	// release
	amx_Release(g_pAmx.front(), params[1]);
	delete [] params;

	return result;
}

int Samp::TextDrawCreate(float x, float y, const char *text)
{
	// init
	const int PARAMS = 3;

	cell *addr;
	cell *params = new cell [PARAMS + 1];

	// set the params
	params[0] = PARAMS * sizeof(cell);
	params[1] = amx_ftoc(x);
	params[2] = amx_ftoc(y);

	int length = strlen(text);
	amx_Allot(g_pAmx.front(), length + 1, &params[3], &addr);
	amx_SetString(addr, text, 0, 0, length + 1);

	// execute
	int result = addr_TextDrawCreate(g_pAmx.front(), params);

	// release
	amx_Release(g_pAmx.front(), params[1]);
	delete [] params;

	return result;
}

int Samp::TextDrawSetString(int text, const char *string)
{
	// init
	const int PARAMS = 2;

	cell *addr;
	cell *params = new cell [PARAMS + 1];

	// set the params
	params[0] = PARAMS * sizeof(cell);
	params[1] = text;

	int length = strlen(string);
	amx_Allot(g_pAmx.front(), length + 1, &params[2], &addr);
	amx_SetString(addr, string, 0, 0, length + 1);

	// execute
	int result = addr_TextDrawSetString(g_pAmx.front(), params);

	// release
	amx_Release(g_pAmx.front(), params[1]);
	delete [] params;

	return result;
}

int Samp::CreatePlayerTextDraw(int playerid, float x, float y, const char *text)
{
	// init
	const int PARAMS = 4;

	cell *addr;
	cell *params = new cell [PARAMS + 1];

	// set the params
	params[0] = PARAMS * sizeof(cell);
	params[1] = playerid;
	params[2] = amx_ftoc(x);
	params[3] = amx_ftoc(y);

	int length = strlen(text);
	amx_Allot(g_pAmx.front(), length + 1, &params[4], &addr);
	amx_SetString(addr, text, 0, 0, length + 1);

	// execute
	int result = addr_CreatePlayerTextDraw(g_pAmx.front(), params);

	// release
	amx_Release(g_pAmx.front(), params[1]);
	delete [] params;

	return result;
}

int Samp::PlayerTextDrawSetString(int playerid, int text, const char *string)
{
	// init
	const int PARAMS = 3;

	cell *addr;
	cell *params = new cell [PARAMS + 1];

	// set the params
	params[0] = PARAMS * sizeof(cell);
	params[1] = playerid;
	params[2] = text;

	int length = strlen(string);
	amx_Allot(g_pAmx.front(), length + 1, &params[3], &addr);
	amx_SetString(addr, string, 0, 0, length + 1);

	// execute
	int result = addr_PlayerTextDrawSetString(g_pAmx.front(), params);

	// release
	amx_Release(g_pAmx.front(), params[1]);
	delete [] params;

	return result;
}

int Samp::CreateMenu(const char *title, int columns, float x, float y, float col1width, float col2width)
{
	// init
	const int PARAMS = 6;

	cell *addr;
	cell *params = new cell [PARAMS + 1];

	// set the params
	params[0] = PARAMS * sizeof(cell);

	int length = strlen(title);
	amx_Allot(g_pAmx.front(), length + 1, &params[1], &addr);
	amx_SetString(addr, title, 0, 0, length + 1);

	params[2] = columns;
	params[3] = amx_ftoc(x);
	params[4] = amx_ftoc(y);
	params[5] = amx_ftoc(col1width);
	params[6] = amx_ftoc(col2width);

	// execute
	int result = addr_CreateMenu(g_pAmx.front(), params);

	// release
	amx_Release(g_pAmx.front(), params[1]);
	delete [] params;

	return result;
}

int Samp::AddMenuItem(int menuid, int column, const char *title)
{
	// init
	const int PARAMS = 3;

	cell *addr;
	cell *params = new cell [PARAMS + 1];

	// set the params
	params[0] = PARAMS * sizeof(cell);

	params[1] = menuid;
	params[2] = column;

	int length = strlen(title);
	amx_Allot(g_pAmx.front(), length + 1, &params[3], &addr);
	amx_SetString(addr, title, 0, 0, length + 1);

	// execute
	int result = addr_AddMenuItem(g_pAmx.front(), params);

	// release
	amx_Release(g_pAmx.front(), params[1]);
	delete [] params;

	return result;
}

int Samp::SetMenuColumnHeader(int menuid, int column, const char *text)
{
	// init
	const int PARAMS = 3;

	cell *addr;
	cell *params = new cell [PARAMS + 1];

	// set the params
	params[0] = PARAMS * sizeof(cell);

	params[1] = menuid;
	params[2] = column;

	int length = strlen(text);
	amx_Allot(g_pAmx.front(), length + 1, &params[3], &addr);
	amx_SetString(addr, text, 0, 0, length + 1);

	// execute
	int result = addr_SetMenuColumnHeader(g_pAmx.front(), params);

	// release
	amx_Release(g_pAmx.front(), params[1]);
	delete [] params;

	return result;
}
