/*
	About: rustext player
	Author: ziggi
*/

#include "russifier.hpp"

std::map <int, Converter::Types> Russifier::gPlayerTypesMap;
Converter::Types Russifier::gDefaultType;

void Russifier::SetPlayerType(int playerid, Converter::Types type)
{
	gPlayerTypesMap[playerid] = type;
}

void Russifier::SetPlayerType(int playerid, int type)
{
	gPlayerTypesMap[playerid] = static_cast<Converter::Types>(type);
}

Converter::Types Russifier::GetPlayerType(int playerid)
{
	if (gPlayerTypesMap.find(playerid) == gPlayerTypesMap.end()) {
		return gDefaultType;
	}
	return gPlayerTypesMap[playerid];
}

void Russifier::SetDefaultType(Converter::Types type)
{
	gDefaultType = type;
}

void Russifier::SetDefaultType(int type)
{
	gDefaultType = static_cast<Converter::Types>(type);
}

Converter::Types Russifier::GetDefaultType()
{
	return gDefaultType;
}