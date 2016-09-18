/*
	About: rustext common
	Author: ziggi
*/

#ifndef COMMON_H
#define COMMON_H

typedef void (*logprintf_t)(const char* format, ...);

typedef int (AMX_NATIVE_CALL *amx_Function_t)(AMX *amx, cell *params);

#ifndef CHECK_PARAMS
	#define CHECK_PARAMS(m,n) \
		if (params[0] != (m * 4)) { \
			logprintf(" * " PLUGIN_NAME ": Incorrect parameter count for \"%s\", %d != %d\n", n, m, (static_cast<int>(params[0])) / 4); \
			return 0; \
		}
#endif

#endif
