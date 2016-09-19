/*
	About: rustext russifier
	Author: ziggi
*/

#ifndef RUSSIFIER_H
#define RUSSIFIER_H

#include <map>
#include "converter.hpp"

class Russifier
{
public:
	static void SetPlayerType(int playerid, Converter::Types type);
	static void SetPlayerType(int playerid, int type);
	static Converter::Types GetPlayerType(int playerid);

	static void SetDefaultType(Converter::Types type);
	static void SetDefaultType(int type);
	static Converter::Types GetDefaultType();

private:
	static std::map <int, Converter::Types> gPlayerTypesMap;
	static Converter::Types gDefaultType;
};

#endif
