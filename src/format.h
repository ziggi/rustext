#ifndef _INCLUDE_FORMATTING_H
#define _INCLUDE_FORMATTING_H

cell* get_amxaddr(AMX *amx,cell amx_addr);
char* format_amxstring(AMX *amx, cell *addr, cell *params, int parm);

//Amx Templatized Cell Printf
template <typename D, typename S>
size_t atcprintf(D *buffer, size_t maxlen, const S *format, AMX *amx, cell *params, int *param);

#endif //_INCLUDE_FORMATTING_H
