/*
	About: rustext hooks
	Author: ziggi
*/

#ifndef HOOKS_H
#define HOOKS_H

#include <memory>
#include <urmem.hpp>
#include <RakNet/BitStream.h>

#ifdef THISCALL
	#undef THISCALL
#endif

#ifdef _WIN32
	#define THISCALL __thiscall
#else
	#define THISCALL
#endif

class Hooks {
public:
	static bool Init();

	static int GetIndexFromPlayerID(const PlayerID &);
	static bool RPC(void *_this, RPCIndex *uniqueID, RakNet::BitStream *bitStream, int priority,
		int reliability, char orderingChannel, PlayerID playerId, bool broadcast, bool shiftTimestamp);

private:
	static void *HOOK_GetRakServerInterface(void);
	static bool THISCALL HOOK_RakServer__RPC(void *_this, RPCIndex *uniqueID, RakNet::BitStream *bitStream, int priority,
		int reliability, char orderingChannel, PlayerID playerId, bool broadcast, bool shiftTimestamp);

	static std::shared_ptr<urmem::hook>
		_hook_get_rak_server_interface,
		_hook_rakserver__rpc;

	static urmem::address_t
		_addr_rakserver,
		_addr_rpc,
		_addr_get_index_from_playerid;
};

#endif
