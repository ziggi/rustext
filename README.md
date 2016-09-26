# rustext
Fix Russian text plugin for SA-MP: GameText's, TextDraw's and Menu's. Default russifier type is SanLtd.

# Usage
Just add rustext[.so] in your **server.cfg** to **plugins** key. If you want to get additional functionality you should copy **rustext.inc** to your libraries directory and add `#include "rustext"` in your script.

# Russifiers
You can download any of the usеd russifiers [here](https://mega.nz/#F!tVhlhDCT!FK1xFcBalTA0ySY_JsryMg).

# Types

```Pawn
enum RussifierType: {
	RussifierType_SanLtd,
	RussifierType_OneC,
	RussifierType_Rush,
	RussifierType_Unknown1,
	RussifierType_Unknown2,
	RussifierType_Unknown3,
	RussifierType_MG,
	RussifierType_Community,
}
```

# Natives

```Pawn
native SetPlayerRussifierType(playerid, RussifierType:type);
native RussifierType:GetPlayerRussifierType(playerid);

native SetDefaultRussifierType(RussifierType:type);
native RussifierType:GetDefaultRussifierType();
```

# Build
```bash
git clone https://github.com/ziggi/rustext.git
mkdir build
cd build
cmake ..
make
```
