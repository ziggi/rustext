/*
	About: rustext natives
	Author: ziggi
*/

#ifndef NATIVES_H
#define NATIVES_H

class Natives {
public:
	static cell AMX_NATIVE_CALL GetRussifierVersion(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL GetRussifierText(AMX *amx, cell *params);

	static cell AMX_NATIVE_CALL SetPlayerRussifierType(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL GetPlayerRussifierType(AMX *amx, cell *params);

	static cell AMX_NATIVE_CALL SetDefaultRussifierType(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL GetDefaultRussifierType(AMX *amx, cell *params);
};

#endif
