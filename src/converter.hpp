/*
	About: rustext converter
	Author: ziggi
*/

#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
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
		MG,
		Community,

		TypesCount
	};
	typedef std::array<std::array<uint8_t, 256>, Types::TypesCount> CharMap_t;

	Converter();
	static void Process(std::string &string, Types type);

private:
	static CharMap_t gCharMap;

};

#endif
