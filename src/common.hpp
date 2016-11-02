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
	RPC_DisplayGameText				= 73,
	RPC_InitMenu					= 76,
	RPC_ShowTextDraw				= 134,
};

// samp textdraw data
#define MAX_TEXT_DRAW_LINE (1024)

#endif
