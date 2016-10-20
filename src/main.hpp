/*
	About: rustext main
	Author: ziggi
*/

#ifndef MAIN_H
#define MAIN_H

#include <list>
#include <map>
#include "common.hpp"
#include "sampfunctions.hpp"
#include "converter.hpp"

logprintf_t logprintf;
GetRakServerInterface_t GetRakServerInterface;

std::list <AMX *> gAmxList;

amx_Function_t Samp::addr_GameTextForAll;
amx_Function_t Samp::addr_GameTextForPlayer;
amx_Function_t Samp::addr_TextDrawCreate;
amx_Function_t Samp::addr_TextDrawSetString;
amx_Function_t Samp::addr_CreatePlayerTextDraw;
amx_Function_t Samp::addr_PlayerTextDrawSetString;
amx_Function_t Samp::addr_CreateMenu;
amx_Function_t Samp::addr_AddMenuItem;
amx_Function_t Samp::addr_SetMenuColumnHeader;

#endif
