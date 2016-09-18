/*
	About: rustext main
	Author: ziggi
*/

#ifndef MAIN_H
#define MAIN_H

#include "common.hpp"
#include "sampfunctions.hpp"

logprintf_t logprintf;
std::list <AMX *> g_pAmx;

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
