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

	if (!Hooks::Init()) {
		logprintf(" " PLUGIN_NAME " " PLUGIN_VERSION " init error.");
		return false;
	}
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
	{"GetRussifierVersion", Natives::GetRussifierVersion},
	{"GetRussifierText", Natives::GetRussifierText},

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
	return amx_Register(amx, PluginNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload( AMX *amx )
{
	gAmxList.remove(amx);
	return AMX_ERR_NONE;
}
