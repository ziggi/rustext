/*
	About: rustext russifier
	Author: ziggi
*/

#ifndef RUSSIFIER_H
#define RUSSIFIER_H

#include "converter.hpp"
#include "common.hpp"

class Russifier
{
public:
	Russifier(bool enabled, Converter::Types russifier);

	static void SetPlayerType(int playerid, Converter::Types type);
	static void SetPlayerType(int playerid, int type);
	static Converter::Types GetPlayerType(int playerid);
	static bool DisablePlayer(int playerid);
	static bool IsPlayerEnabled(int playerid);

	static void SetDefaultType(Converter::Types type);
	static void SetDefaultType(int type);
	static Converter::Types GetDefaultType();
	static bool DisableDefault();
	static bool IsDefaultEnabled();

private:
	static Converter::Types gPlayerTypesMap[MAX_PLAYERS];
	static Converter::Types gDefaultType;
	static bool gIsPlayerEnabled[MAX_PLAYERS];
	static bool gIsDefaultEnabled;
};

#endif
