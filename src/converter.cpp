/*
	About: rustext converter
	Author: ziggi
	Thanks Fro1sha for SanLtd symbol codes
*/

#include "converter.hpp"

Converter::CharMap_t Converter::gCharMap;

Converter::Converter()
{
	gCharMap = {};
	gCharMap[224] = /* а */ {{97,  97,  97,  97,  65,  65,  65,  97,  97}};
	gCharMap[192] = /* А */ {{65,  65,  65,  65,  65,  65,  65,  65,  65}};
	gCharMap[225] = /* б */ {{151, 152, 151, 151, 128, 54,  133, 151, 151}};
	gCharMap[193] = /* Б */ {{128, 129, 128, 128, 128, 54,  133, 128, 128}};
	gCharMap[226] = /* в */ {{162, 162, 152, 152, 129, 66,  66,  171, 171}};
	gCharMap[194] = /* В */ {{139, 139, 129, 129, 129, 66,  66,  66,  66}};
	gCharMap[227] = /* г */ {{153, 159, 153, 153, 130, 70,  134, 164, 164}};
	gCharMap[195] = /* Г */ {{130, 136, 130, 130, 130, 70,  134, 141, 141}};
	gCharMap[228] = /* д */ {{154, 154, 154, 154, 131, 68,  128, 153, 153}};
	gCharMap[196] = /* Д */ {{131, 131, 131, 131, 131, 68,  128, 130, 130}};
	gCharMap[229] = /* е */ {{101, 101, 101, 101, 69,  69,  69,  101, 101}};
	gCharMap[197] = /* Е */ {{69,  69,  69,  69,  69,  69,  69,  69,  69}};
	gCharMap[184] = /* ё */ {{101, 160, 175, 101, 69,  137, 137, 101, 0}};
	gCharMap[168] = /* Ё */ {{69,  137, 69,  69,  69,  137, 137, 69,  0}};
	gCharMap[230] = /* ж */ {{155, 155, 155, 155, 149, 71,  132, 154, 154}};
	gCharMap[198] = /* Ж */ {{132, 132, 132, 132, 149, 71,  132, 131, 131}};
	gCharMap[231] = /* з */ {{159, 156, 159, 159, 138, 51,  51,  150, 150}};
	gCharMap[199] = /* З */ {{136, 133, 136, 136, 138, 51,  51,  147, 147}};
	gCharMap[232] = /* и */ {{156, 157, 156, 156, 139, 78,  129, 155, 155}};
	gCharMap[200] = /* И */ {{133, 134, 133, 133, 139, 78,  129, 132, 132}};
	gCharMap[233] = /* й */ {{157, 158, 157, 157, 140, 78,  173, 156, 156}};
	gCharMap[201] = /* Й */ {{134, 135, 134, 134, 140, 78,  173, 133, 133}};
	gCharMap[234] = /* к */ {{107, 107, 107, 107, 75,  75,  75,  175, 175}};
	gCharMap[202] = /* К */ {{75,  75,  75,  75,  75,  75,  75,  75,  75}};
	gCharMap[235] = /* л */ {{158, 161, 158, 158, 132, 76,  130, 157, 157}};
	gCharMap[203] = /* Л */ {{135, 138, 135, 135, 132, 76,  130, 134, 134}};
	gCharMap[236] = /* м */ {{175, 109, 109, 175, 77,  77,  77,  159, 159}};
	gCharMap[204] = /* М */ {{77,  77,  77,  77,  77,  77,  77,  77,  77}};
	gCharMap[237] = /* н */ {{174, 164, 174, 174, 72,  72,  72,  172, 172}};
	gCharMap[205] = /* Н */ {{72,  141, 72,  72,  72,  72,  72,  72,  72}};
	gCharMap[238] = /* о */ {{111, 111, 111, 111, 79,  79,  79,  111, 111}};
	gCharMap[206] = /* О */ {{79,  79,  79,  79,  79,  79,  79,  79,  79}};
	gCharMap[239] = /* п */ {{163, 163, 163, 163, 150, 90,  146, 174, 174}};
	gCharMap[207] = /* П */ {{140, 140, 140, 140, 150, 90,  146, 135, 135}};
	gCharMap[240] = /* р */ {{112, 112, 112, 112, 80,  80,  80,  112, 112}};
	gCharMap[208] = /* Р */ {{80,  80,  80,  80,  80,  80,  80,  80,  80}};
	gCharMap[241] = /* с */ {{99,  99,  99,  99,  67,  67,  67,  99,  99}};
	gCharMap[209] = /* С */ {{67,  67,  67,  67,  67,  67,  67,  67,  67}};
	gCharMap[242] = /* т */ {{166, 116, 166, 166, 84,  84,  84,  116, 116}};
	gCharMap[210] = /* Т */ {{143, 84,  143, 143, 84,  84,  84,  84,  84}};
	gCharMap[243] = /* у */ {{121, 121, 121, 121, 137, 89,  147, 121, 121}};
	gCharMap[211] = /* У */ {{89,  89,  150, 89,  137, 89,  147, 136, 136}};
	gCharMap[244] = /* ф */ {{152, 167, 162, 152, 142, 86,  142, 152, 152}};
	gCharMap[212] = /* Ф */ {{129, 144, 139, 129, 142, 86,  142, 129, 129}};
	gCharMap[245] = /* х */ {{120, 120, 120, 120, 88,  88,  88,  120, 120}};
	gCharMap[213] = /* Х */ {{88,  88,  88,  88,  88,  88,  88,  88,  88}};
	gCharMap[246] = /* ц */ {{160, 168, 160, 160, 134, 81,  148, 161, 161}};
	gCharMap[214] = /* Ц */ {{137, 145, 137, 137, 134, 81,  148, 138, 138}};
	gCharMap[247] = /* ч */ {{164, 153, 164, 164, 135, 52,  52,  162, 162}};
	gCharMap[215] = /* Ч */ {{141, 130, 141, 141, 135, 52,  52,  139, 139}};
	gCharMap[248] = /* ш */ {{165, 165, 165, 165, 141, 87,  144, 163, 163}};
	gCharMap[216] = /* Ш */ {{142, 142, 142, 142, 141, 87,  144, 140, 140}};
	gCharMap[249] = /* щ */ {{161, 169, 161, 161, 136, 87,  144, 160, 160}};
	gCharMap[217] = /* Щ */ {{138, 146, 138, 138, 136, 87,  144, 137, 137}};
	gCharMap[250] = /* ъ */ {{167, 170, 167, 167, 143, 74,  136, 165, 0}};
	gCharMap[218] = /* Ъ */ {{144, 147, 144, 144, 143, 74,  136, 142, 0}};
	gCharMap[251] = /* ы */ {{168, 171, 168, 168, 144, 83,  131, 166, 0}};
	gCharMap[219] = /* Ы */ {{145, 148, 145, 145, 144, 83,  131, 143, 0}};
	gCharMap[252] = /* ь */ {{169, 172, 169, 169, 145, 74,  136, 167, 167}};
	gCharMap[220] = /* Ь */ {{146, 149, 146, 146, 145, 74,  136, 144, 144}};
	gCharMap[253] = /* э */ {{170, 166, 170, 170, 146, 51,  135, 168, 0}};
	gCharMap[221] = /* Э */ {{147, 143, 147, 147, 146, 51,  135, 145, 0}};
	gCharMap[254] = /* ю */ {{171, 151, 171, 171, 147, 85,  145, 169, 169}};
	gCharMap[222] = /* Ю */ {{148, 128, 148, 148, 147, 85,  145, 146, 146}};
	gCharMap[255] = /* я */ {{172, 174, 172, 172, 148, 82,  149, 170, 170}};
	gCharMap[223] = /* Я */ {{149, 173, 149, 149, 148, 82,  149, 173, 173}};
	gCharMap[42]  = /* * */ {{93,  93,  93,  93,  93,  93,  93,  93,  93}};
	gCharMap[64]  = /* @ */ {{124, 124, 124, 124, 124, 124, 124, 124, 124}};
	// Ukraine
	gCharMap[165] = /* Ѓ */ {{0,   0,   0,   0,   0,   0,   0,   0,   141}};
	gCharMap[180] = /* ѓ */ {{0,   0,   0,   0,   0,   0,   0,   0,   164}};
	gCharMap[170] = /* Є */ {{0,   0,   0,   0,   0,   0,   0,   0,   145}};
	gCharMap[186] = /* є */ {{0,   0,   0,   0,   0,   0,   0,   0,   168}};
	gCharMap[178] = /* І */ {{0,   0,   0,   0,   0,   0,   0,   0,   73}};
	gCharMap[179] = /* і */ {{0,   0,   0,   0,   0,   0,   0,   0,   105}};
	gCharMap[175] = /* Ї */ {{0,   0,   0,   0,   0,   0,   0,   0,   142}};
	gCharMap[191] = /* ї */ {{0,   0,   0,   0,   0,   0,   0,   0,   165}};
}

void Converter::Process(std::string &string, Converter::Types type)
{
	uint8_t code;
	for (auto &c : string) {
		code = gCharMap[c & 0xFF][type];
		if (code != 0) {
			c = code;
		}
	}
}

void Converter::Process(char *string, Converter::Types type)
{
	uint8_t code;
	while (string[i]) {
		code = gCharMap[string[i] & 0xFF][type];
		if (code != 0) {
			string[i] = code;
		}
		i++;
	}
}

void Converter::Process(char *string, Converter::Types type)
{
	uint i = 0;
	uint8_t code;
	while (string[i]) {
		code = gCharMap[string[i] & 0xFF][type];
		if (code != 0) {
			string[i] = code;
		}
		i++;
	}
}
