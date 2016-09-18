//----------------------------------------------------------
//
//   SA-MP Multiplayer Modification For GTA:SA
//   Copyright 2013 SA-MP Team, Dan
//
//----------------------------------------------------------

#pragma once

//----------------------------------------------------------

#include <string>

//----------------------------------------------------------

#include "amx.h"

//----------------------------------------------------------

#define USENAMETABLE(hdr) \
	((hdr)->defsize==sizeof(AMX_FUNCSTUBNT))

#define NUMENTRIES(hdr,field,nextfield) \
	(unsigned)(((hdr)->nextfield - (hdr)->field) / (hdr)->defsize)

#define GETENTRY(hdr,table,index) \
	(AMX_FUNCSTUB *)((unsigned char*)(hdr) + (unsigned)(hdr)->table + (unsigned)index*(hdr)->defsize)

#define GETENTRYNAME(hdr,entry) \
	(USENAMETABLE(hdr) ? \
		(char *)((unsigned char*)(hdr) + (unsigned)((AMX_FUNCSTUBNT*)(entry))->nameofs) : \
		((AMX_FUNCSTUB*)(entry))->name)

//----------------------------------------------------------

extern int AMXAPI amx_PushAddress(AMX *amx, cell *address);
extern void AMXAPI amx_Redirect(AMX *amx, const char *from, ucell to, AMX_NATIVE *store);
extern int AMXAPI amx_GetCString(AMX *amx, cell param, char *&dest);
extern void AMXAPI amx_SetCString(AMX *amx, cell param, const char *str, int len);
extern std::string AMXAPI amx_GetCppString(AMX *amx, cell param);
extern void AMXAPI amx_SetCppString(AMX *amx, cell param, std::string str, int len);

//----------------------------------------------------------
// EOF
