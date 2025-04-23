/*
	About: rustext common
	Author: ziggi
*/

#ifndef COMMON_H
#define COMMON_H

#include <sdk/plugin.h>

#define MAX_PLAYERS 1000

typedef void (*logprintf_t)(const char* format, ...);

typedef int (AMX_NATIVE_CALL *amx_Function_t)(AMX *amx, cell *params);

#endif
