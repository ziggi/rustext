/*
	About: rustext converter
	Author: ziggi
*/

#ifndef CONVERTER_H
#define CONVERTER_H

#include <map>
#include <array>

class Converter
{
public:
	enum Types
	{
		SanLtd,
		OneC,
		Rush,
		Unknown1,
		Unknown2,
		Unknown3,

		TypesCount
	};

	static void Process(std::string &string, Converter::Types type);

private:
	static std::map <int, std::array<int, Converter::Types::TypesCount>> gConverterMap;

};

#endif
