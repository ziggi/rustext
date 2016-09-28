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
	RussifierType_Ukraine,
}

// Natives
native SetPlayerRussifierType(playerid, RussifierType:type);
native RussifierType:GetPlayerRussifierType(playerid);

native SetDefaultRussifierType(RussifierType:type);
native RussifierType:GetDefaultRussifierType();
