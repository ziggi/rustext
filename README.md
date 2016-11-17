# rustext
Fix Russian text plugin for SA-MP: GameText's, TextDraw's and Menu's. Default russifier type is SanLtd.

# Usage
Just add rustext[.so] in your **server.cfg** to **plugins** key. If you want to get additional functionality you should copy **rustext.inc** to your libraries directory and add `#include "rustext"` in your script.

# Russifiers
You can download any of the usеd russifiers [here](https://mega.nz/#F!tVhlhDCT!FK1xFcBalTA0ySY_JsryMg).

# Examples
Here you can see how it works with SanLtd russifier:
![sanltd](https://cloud.githubusercontent.com/assets/1020099/18914954/db9b4ade-8597-11e6-8d72-783cfd24fb99.png)
Here you can see how it works with Ukraine localization:
![ukraine](https://cloud.githubusercontent.com/assets/1020099/18914955/db9d95dc-8597-11e6-9c2b-6ae5cc05bc72.png)

# Example of usage
```Pawn
#include <a_samp>
#include <rustext>

static
	TextRusTD[RussifierType];

const
	Float:TEXT_BASE_X = 240.0,
	Float:TEXT_BASE_Y = 200.0,
	TEXT_RUSSIFIERS_COUNT = sizeof(TextRusTD) - 1; // minus Ukraine

public OnGameModeInit()
{
	for (new i; i < TEXT_RUSSIFIERS_COUNT; i++) {
		TextRusTD[RussifierType:i] = _:TextDrawCreate(TEXT_BASE_X,
		                                              TEXT_BASE_Y + 10.0 * i,
		                                              "Я могу прочитать этот текст, это мой русификатор");
		TextDrawSetSelectable(Text:TextRusTD[RussifierType:i], 1);
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
	for (new i; i < TEXT_RUSSIFIERS_COUNT; i++) {
		SetPlayerRussifierType(playerid, RussifierType:i);
		TextDrawShowForPlayer(playerid, Text:TextRusTD[RussifierType:i]);
	}
	return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	for (new i; i < TEXT_RUSSIFIERS_COUNT; i++) {
		if (TextRusTD[RussifierType:i] == _:clickedid) {
			SetPlayerRussifierType(playerid, RussifierType:i);
			return 1;
		}
	}
	return 0;
}
```

# Types

```Pawn
enum RussifierType: {
	RussifierType_Disabled = -1,
	RussifierType_SanLtd = 0,
	RussifierType_OneC,
	RussifierType_Rush,
	RussifierType_Unknown1,
	RussifierType_Unknown2,
	RussifierType_Unknown3,
	RussifierType_MG,
	RussifierType_Community,
	RussifierType_Ukraine,
}
```

# Natives

```Pawn
native GetRussifierVersion(version[], const size = sizeof(version));
native GetRussifierText(RussifierType:type, string[], string_return[], const size = sizeof(string_return));

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

# Build (Visual Studio)
```bash
cd FCNPC
mkdir build
cd build
cmake .. -G "Visual Studio 12"
```
