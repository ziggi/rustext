/*
	About: rustext include
	Author: ziggi
*/

#if defined _rustext_included
	#endinput
#endif
#define _rustext_included
#pragma library rustext

// Enums
enum RussifierType: {
	RussifierType_Disabled = -1,
	RussifierType_SanLtd = 0,
	RussifierType_OneC,
	RussifierType_Rush,
	RussifierType_Unknown1,
	RussifierType_Unknown2,
	RussifierType_Unknown3,
	RussifierType_MG,
	RussifierType_Community,
	RussifierType_Ukrainian,
	RussifierType_Hungarian,
}

// RussifierType_Ukraine is deprecated
#define RussifierType_Ukraine RussifierType_Ukrainian

// Natives
native GetRussifierVersion(version[], const size = sizeof(version));
native GetRussifierText(RussifierType:type, string[], string_return[], const size = sizeof(string_return));

native SetPlayerRussifierType(playerid, RussifierType:type);
native RussifierType:GetPlayerRussifierType(playerid);

native SetDefaultRussifierType(RussifierType:type);
native RussifierType:GetDefaultRussifierType();
