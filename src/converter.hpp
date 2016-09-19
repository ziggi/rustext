/*
	About: rustext converter
	Author: ziggi
*/

#ifndef CONVERTER_H
#define CONVERTER_H

#include <map>

class Converter {
public:
	static void Process(std::string &string);

private:
	static std::map <int, int> gConverterMap;
};

#endif
