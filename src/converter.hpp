/*
	About: rustext converter
	Author: ziggi
*/

#ifndef CONVERTER_H
#define CONVERTER_H

#include <map>

class Converter {
public:
	static bool Process(std::string &string);

private:
	static std::map <char, int> gConverterMap;
};

#endif
