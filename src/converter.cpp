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
	gCharMap[224] = {{97,  97,  97,  97,  65,  65,  65,  97,  97,  0  }}; /* а */
	gCharMap[192] = {{65,  65,  65,  65,  65,  65,  65,  65,  65,  0  }}; /* А */
	gCharMap[225] = {{151, 152, 151, 151, 128, 54,  133, 151, 151, 152}}; /* б */
	gCharMap[193] = {{128, 129, 128, 128, 128, 54,  133, 128, 128, 129}}; /* Б */
	gCharMap[226] = {{162, 162, 152, 152, 129, 66,  66,  171, 171, 0  }}; /* в */
	gCharMap[194] = {{139, 139, 129, 129, 129, 66,  66,  66,  66,  0  }}; /* В */
	gCharMap[227] = {{153, 159, 153, 153, 130, 70,  134, 164, 164, 0  }}; /* г */
	gCharMap[195] = {{130, 136, 130, 130, 130, 70,  134, 141, 141, 0  }}; /* Г */
	gCharMap[228] = {{154, 154, 154, 154, 131, 68,  128, 153, 153, 0  }}; /* д */
	gCharMap[196] = {{131, 131, 131, 131, 131, 68,  128, 130, 130, 0  }}; /* Д */
	gCharMap[229] = {{101, 101, 101, 101, 69,  69,  69,  101, 101, 0  }}; /* е */
	gCharMap[197] = {{69,  69,  69,  69,  69,  69,  69,  69,  69,  0  }}; /* Е */
	gCharMap[184] = {{101, 160, 175, 101, 69,  137, 137, 101, 0,   0  }}; /* ё */
	gCharMap[168] = {{69,  137, 69,  69,  69,  137, 137, 69,  0,   0  }}; /* Ё */
	gCharMap[230] = {{155, 155, 155, 155, 149, 71,  132, 154, 154, 0  }}; /* ж */
	gCharMap[198] = {{132, 132, 132, 132, 149, 71,  132, 131, 131, 0  }}; /* Ж */
	gCharMap[231] = {{159, 156, 159, 159, 138, 51,  51,  150, 150, 0  }}; /* з */
	gCharMap[199] = {{136, 133, 136, 136, 138, 51,  51,  147, 147, 0  }}; /* З */
	gCharMap[232] = {{156, 157, 156, 156, 139, 78,  129, 155, 155, 0  }}; /* и */
	gCharMap[200] = {{133, 134, 133, 133, 139, 78,  129, 132, 132, 0  }}; /* И */
	gCharMap[233] = {{157, 158, 157, 157, 140, 78,  173, 156, 156, 158}}; /* й */
	gCharMap[201] = {{134, 135, 134, 134, 140, 78,  173, 133, 133, 135}}; /* Й */
	gCharMap[234] = {{107, 107, 107, 107, 75,  75,  75,  175, 175, 0  }}; /* к */
	gCharMap[202] = {{75,  75,  75,  75,  75,  75,  75,  75,  75,  0  }}; /* К */
	gCharMap[235] = {{158, 161, 158, 158, 132, 76,  130, 157, 157, 0  }}; /* л */
	gCharMap[203] = {{135, 138, 135, 135, 132, 76,  130, 134, 134, 0  }}; /* Л */
	gCharMap[236] = {{175, 109, 109, 175, 77,  77,  77,  159, 159, 0  }}; /* м */
	gCharMap[204] = {{77,  77,  77,  77,  77,  77,  77,  77,  77,  0  }}; /* М */
	gCharMap[237] = {{174, 164, 174, 174, 72,  72,  72,  172, 172, 162}}; /* н */
	gCharMap[205] = {{72,  141, 72,  72,  72,  72,  72,  72,  72,  139}}; /* Н */
	gCharMap[238] = {{111, 111, 111, 111, 79,  79,  79,  111, 111, 0  }}; /* о */
	gCharMap[206] = {{79,  79,  79,  79,  79,  79,  79,  79,  79,  0  }}; /* О */
	gCharMap[239] = {{163, 163, 163, 163, 150, 90,  146, 174, 174, 0  }}; /* п */
	gCharMap[207] = {{140, 140, 140, 140, 150, 90,  146, 135, 135, 0  }}; /* П */
	gCharMap[240] = {{112, 112, 112, 112, 80,  80,  80,  112, 112, 0  }}; /* р */
	gCharMap[208] = {{80,  80,  80,  80,  80,  80,  80,  80,  80,  0  }}; /* Р */
	gCharMap[241] = {{99,  99,  99,  99,  67,  67,  67,  99,  99,  0  }}; /* с */
	gCharMap[209] = {{67,  67,  67,  67,  67,  67,  67,  67,  67,  0  }}; /* С */
	gCharMap[242] = {{166, 116, 166, 166, 84,  84,  84,  116, 116, 0  }}; /* т */
	gCharMap[210] = {{143, 84,  143, 143, 84,  84,  84,  84,  84,  0  }}; /* Т */
	gCharMap[243] = {{121, 121, 121, 121, 137, 89,  147, 121, 121, 166}}; /* у */
	gCharMap[211] = {{89,  89,  150, 89,  137, 89,  147, 136, 136, 143}}; /* У */
	gCharMap[244] = {{152, 167, 162, 152, 142, 86,  142, 152, 152, 0  }}; /* ф */
	gCharMap[212] = {{129, 144, 139, 129, 142, 86,  142, 129, 129, 0  }}; /* Ф */
	gCharMap[245] = {{120, 120, 120, 120, 88,  88,  88,  120, 120, 167}}; /* х ő */
	gCharMap[213] = {{88,  88,  88,  88,  88,  88,  88,  88,  88,  144}}; /* Х Ő */
	gCharMap[246] = {{160, 168, 160, 160, 134, 81,  148, 161, 161, 168}}; /* ц */
	gCharMap[214] = {{137, 145, 137, 137, 134, 81,  148, 138, 138, 145}}; /* Ц */
	gCharMap[247] = {{164, 153, 164, 164, 135, 52,  52,  162, 162, 0  }}; /* ч */
	gCharMap[215] = {{141, 130, 141, 141, 135, 52,  52,  139, 139, 0  }}; /* Ч */
	gCharMap[248] = {{165, 165, 165, 165, 141, 87,  144, 163, 163, 0  }}; /* ш */
	gCharMap[216] = {{142, 142, 142, 142, 141, 87,  144, 140, 140, 0  }}; /* Ш */
	gCharMap[249] = {{161, 169, 161, 161, 136, 87,  144, 160, 160, 0  }}; /* щ */
	gCharMap[217] = {{138, 146, 138, 138, 136, 87,  144, 137, 137, 0  }}; /* Щ */
	gCharMap[250] = {{167, 170, 167, 167, 143, 74,  136, 165, 0,   170}}; /* ъ */
	gCharMap[218] = {{144, 147, 144, 144, 143, 74,  136, 142, 0,   147}}; /* Ъ */
	gCharMap[251] = {{168, 171, 168, 168, 144, 83,  131, 166, 0,   171}}; /* ы ű */
	gCharMap[219] = {{145, 148, 145, 145, 144, 83,  131, 143, 0,   183}}; /* Ы Ű */
	gCharMap[252] = {{169, 172, 169, 169, 145, 74,  136, 167, 167, 172}}; /* ь */
	gCharMap[220] = {{146, 149, 146, 146, 145, 74,  136, 144, 144, 149}}; /* Ь */
	gCharMap[253] = {{170, 166, 170, 170, 146, 51,  135, 168, 0,   0  }}; /* э */
	gCharMap[221] = {{147, 143, 147, 147, 146, 51,  135, 145, 0,   0  }}; /* Э */
	gCharMap[254] = {{171, 151, 171, 171, 147, 85,  145, 169, 169, 0  }}; /* ю */
	gCharMap[222] = {{148, 128, 148, 148, 147, 85,  145, 146, 146, 0  }}; /* Ю */
	gCharMap[255] = {{172, 174, 172, 172, 148, 82,  149, 170, 170, 0  }}; /* я */
	gCharMap[223] = {{149, 173, 149, 149, 148, 82,  149, 173, 173, 0  }}; /* Я */
	gCharMap[42]  = {{93,  93,  93,  93,  93,  93,  93,  93,  93,  93 }}; /* * */
	gCharMap[64]  = {{124, 124, 124, 124, 124, 124, 124, 124, 124, 124}}; /* @ */
	// Ukraine
	gCharMap[165] = {{0,   0,   0,   0,   0,   0,   0,   0,   141, 0  }}; /* Ѓ */
	gCharMap[180] = {{0,   0,   0,   0,   0,   0,   0,   0,   164, 0  }}; /* ѓ */
	gCharMap[170] = {{0,   0,   0,   0,   0,   0,   0,   0,   145, 0  }}; /* Є */
	gCharMap[186] = {{0,   0,   0,   0,   0,   0,   0,   0,   168, 0  }}; /* є */
	gCharMap[178] = {{0,   0,   0,   0,   0,   0,   0,   0,   73,  0  }}; /* І */
	gCharMap[179] = {{0,   0,   0,   0,   0,   0,   0,   0,   105, 0  }}; /* і */
	gCharMap[175] = {{0,   0,   0,   0,   0,   0,   0,   0,   142, 0  }}; /* Ї */
	gCharMap[191] = {{0,   0,   0,   0,   0,   0,   0,   0,   165, 0  }}; /* ї */
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

void Converter::Process(char *string, uint32_t length, Converter::Types type)
{
	uint8_t code;
	for (uint32_t i = 0; i < length; i++) {
		code = gCharMap[string[i] & 0xFF][type];
		if (code != 0) {
			string[i] = code;
		}
	}
}
