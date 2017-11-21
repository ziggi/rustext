/*
	About: rustext player
	Author: ziggi
*/

#include "russifier.hpp"

Converter::Types Russifier::gPlayerTypesMap[MAX_PLAYERS];
Converter::Types Russifier::gDefaultType;
bool Russifier::gIsPlayerEnabled[MAX_PLAYERS];
bool Russifier::gIsDefaultEnabled;

Russifier::Russifier(bool enabled, Converter::Types russifier)
{
	gIsDefaultEnabled = enabled;
	gDefaultType = russifier;

	for (int playerid = 0; playerid < MAX_PLAYERS; playerid++) {
		gIsPlayerEnabled[playerid] = false;
		gPlayerTypesMap[playerid] = russifier;
	}
}

/*
	Player
*/

void Russifier::SetPlayerType(int playerid, Converter::Types type)
{
	gIsPlayerEnabled[playerid] = true;
	gPlayerTypesMap[playerid] = type;
}

void Russifier::SetPlayerType(int playerid, int type)
{
	SetPlayerType(playerid, static_cast<Converter::Types>(type));
}

Converter::Types Russifier::GetPlayerType(int playerid)
{
	return gPlayerTypesMap[playerid];
}

void Russifier::DisablePlayer(int playerid)
{
	gIsPlayerEnabled[playerid] = false;
}

bool Russifier::IsPlayerEnabled(int playerid)
{
	return gIsPlayerEnabled[playerid];
}

/*
	Default
*/

void Russifier::SetDefaultType(Converter::Types type)
{
	gIsDefaultEnabled = true;
	gDefaultType = type;
}

void Russifier::SetDefaultType(int type)
{
	SetDefaultType(static_cast<Converter::Types>(type));
}

Converter::Types Russifier::GetDefaultType()
{
	return gDefaultType;
}

void Russifier::DisableDefault()
{
	gIsDefaultEnabled = false;
}

bool Russifier::IsDefaultEnabled()
{
	return gIsDefaultEnabled;
}

/*
	Other
*/

bool Russifier::IsEnabledForPlayer(int playerid)
{
	return IsPlayerEnabled(playerid) || IsDefaultEnabled();
}
