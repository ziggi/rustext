/*
	About: rustext converter
	Author: ziggi
*/

#ifndef CONVERTER_H
#define CONVERTER_H

#include <map>

class Converter
{
public:
	struct Types
	{
		int SanLtd;
		int OneC;
		int Rush;
		int Unknown1;
		int Unknown2;
		int Unknown3;
	};

	static void Process(std::string &string);

private:
	static std::map <int, Converter::Types> gConverterMap;

};

#endif
