/*
	About: rustext common
	Author: ziggi
*/

#ifndef COMMON_H
#define COMMON_H

#include <sdk/plugin.h>

#define MAX_PLAYERS 1000

typedef void (*logprintf_t)(const char* format, ...);
typedef int (*GetRakServerInterface_t)();
typedef int (AMX_NATIVE_CALL *amx_Function_t)(AMX *amx, cell *params);

#ifndef CHECK_PARAMS
	#define CHECK_PARAMS(m,n) \
		if (params[0] != (m * 4)) { \
			logprintf(" * " PLUGIN_NAME ": Incorrect parameter count for \"%s\", %d != %d\n", n, m, (static_cast<int>(params[0])) / 4); \
			return 0; \
		}
#endif

// plugin data
#define PLUGIN_DATA_NETGAME        225
#define PLUGIN_DATA_RAKSERVER      226
#define PLUGIN_DATA_LOADFSCRIPT    227
#define PLUGIN_DATA_CONSOLE        228
#define PLUGIN_DATA_UNLOADFSCRIPT  229

// rpc data
enum RPCEnumeration {
	RPC_ShowTextDraw				= 134,
};

// samp textdraw data
#define MAX_TEXT_DRAWS (2048)
#define MAX_PLAYER_TEXT_DRAWS (256)
#define MAX_TEXT_DRAW_LINE (1024)

#ifndef _WIN32
	#define BOOL    int32_t
	#define DWORD   uint32_t
	#define BYTE    uint8_t
	#define WORD    uint16_t
#endif

typedef struct CTextdraw
{
	union
	{
		BYTE byteFlags;			// 25
		struct
		{
			BYTE byteBox : 1;
			BYTE byteLeft : 1;
			BYTE byteRight : 1;
			BYTE byteCenter : 1;
			BYTE byteProportional : 1;
			BYTE bytePadding : 3;
		};
	};
	float			fLetterWidth;			// 1
	float			fLetterHeight;		// 5
	DWORD			dwLetterColor;		// 9
	float			fLineWidth;			// 13
	float			fLineHeight;			// 17
	DWORD			dwBoxColor;			// 21
	BYTE			byteShadow; // 26
	BYTE			byteOutline; // 27
	DWORD			dwBackgroundColor; // 31
	BYTE			byteStyle; // 32
	BYTE			byteSelectable; // 32
	float			fX; // 33
	float			fY; // 37
	WORD			dwModelIndex; // 41 - 43
	float			fRotX; // 43 - 47
	float			fRotY; // 47 - 51
	float			fRotZ; // 51 - 55
	float			fZoom; // 55 - 59
	WORD			color1; // 59 - 61
	WORD			color2; // 61 - 63
} _CTextdraw;

#endif
