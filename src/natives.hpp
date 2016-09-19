/*
	About: rustext natives
	Author: ziggi
*/

#ifndef NATIVES_H
#define NATIVES_H

class Natives {
public:
	static cell AMX_NATIVE_CALL SetPlayerRussifierType(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL GetPlayerRussifierType(AMX *amx, cell *params);

	static cell AMX_NATIVE_CALL SetDefaultRussifierType(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL GetDefaultRussifierType(AMX *amx, cell *params);

	// redirected functions
	static cell AMX_NATIVE_CALL GameTextForAll(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL GameTextForPlayer(AMX *amx, cell *params);

	static cell AMX_NATIVE_CALL TextDrawCreate(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL TextDrawSetString(AMX *amx, cell *params);

	static cell AMX_NATIVE_CALL CreatePlayerTextDraw(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL PlayerTextDrawSetString(AMX *amx, cell *params);

	static cell AMX_NATIVE_CALL CreateMenu(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL AddMenuItem(AMX *amx, cell *params);
	static cell AMX_NATIVE_CALL SetMenuColumnHeader(AMX *amx, cell *params);
};

#endif
