/*
	About: rustext main
	Author: ziggi
*/

#include <sdk/plugin.h>
#include <sdk/amx/amx2.h>
#include <list>
#include "main.hpp"
#include "natives.hpp"
#include "common.hpp"
#include "sampfunctions.hpp"
#include "converter.hpp"
#include "russifier.hpp"
#include "hooks.hpp"

extern void *pAMXFunctions;

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = reinterpret_cast<logprintf_t>(ppData[PLUGIN_DATA_LOGPRINTF]);
	GetRakServerInterface = reinterpret_cast<GetRakServerInterface_t>(ppData[PLUGIN_DATA_RAKSERVER]);

	Converter();
	Russifier(true, Converter::Types::SanLtd);

	logprintf("");
	logprintf("---------------");
	logprintf(" " PLUGIN_NAME " " PLUGIN_VERSION);
	logprintf(" Author: ziggi");
	logprintf("---------------");
	logprintf("");
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf(" * " PLUGIN_NAME " " PLUGIN_VERSION " unloaded.");
}

AMX_NATIVE_INFO PluginNatives[] = {
	{"SetPlayerRussifierType", Natives::SetPlayerRussifierType},
	{"GetPlayerRussifierType", Natives::GetPlayerRussifierType},

	{"SetDefaultRussifierType", Natives::SetDefaultRussifierType},
	{"GetDefaultRussifierType", Natives::GetDefaultRussifierType},

	{0, 0}
};

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad( AMX *amx )
{
	gAmxList.push_back(amx);

	amx_Redirect(amx, "GameTextForAll", reinterpret_cast<ucell>(Natives::GameTextForAll), &Samp::addr_GameTextForAll);
	amx_Redirect(amx, "GameTextForPlayer", reinterpret_cast<ucell>(Natives::GameTextForPlayer), &Samp::addr_GameTextForPlayer);

	amx_Redirect(amx, "TextDrawCreate", reinterpret_cast<ucell>(Natives::TextDrawCreate), &Samp::addr_TextDrawCreate);
	amx_Redirect(amx, "TextDrawSetString", reinterpret_cast<ucell>(Natives::TextDrawSetString), &Samp::addr_TextDrawSetString);

	amx_Redirect(amx, "CreatePlayerTextDraw", reinterpret_cast<ucell>(Natives::CreatePlayerTextDraw), &Samp::addr_CreatePlayerTextDraw);
	amx_Redirect(amx, "PlayerTextDrawSetString", reinterpret_cast<ucell>(Natives::PlayerTextDrawSetString), &Samp::addr_PlayerTextDrawSetString);

	amx_Redirect(amx, "CreateMenu", reinterpret_cast<ucell>(Natives::CreateMenu), &Samp::addr_CreateMenu);
	amx_Redirect(amx, "AddMenuItem", reinterpret_cast<ucell>(Natives::AddMenuItem), &Samp::addr_AddMenuItem);
	amx_Redirect(amx, "SetMenuColumnHeader", reinterpret_cast<ucell>(Natives::SetMenuColumnHeader), &Samp::addr_SetMenuColumnHeader);

	return amx_Register(amx, PluginNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload( AMX *amx )
{
	gAmxList.remove(amx);
	return AMX_ERR_NONE;
}
