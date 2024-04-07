/*
	About: rustext converter
	Author: ziggi
*/

#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <array>
#include <cstdint>

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
		Ukraine,
		Hungarian,

		TypesCount
	};
	typedef std::array<std::array<uint8_t, Types::TypesCount>, 256> CharMap_t;

	Converter();
	static void Process(std::string &string, Types type);
	static void Process(char *string, uint32_t length, Types type);

private:
	static CharMap_t gCharMap;

};

#endif
