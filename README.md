# rustext
Fix Russian text plugin for SA-MP: GameText's, TextDraw's and Menu's. Default russifier type is SanLtd.

This version of the plugin doesn't use memhack, so it can be used in [open.mp](https://www.open.mp/) runtime.

# Usage
Just add rustext[.so] in your **server.cfg** to **plugins** key. If you want to get additional functionality you should copy **rustext.inc** to your libraries directory and add `#include "rustext"` in your script.

# Russifiers
You can download any of the usеd russifiers [here](https://mega.nz/#F!tVhlhDCT!FK1xFcBalTA0ySY_JsryMg).

# Examples
Here you can see how it works with SanLtd russifier:

![sanltd](https://cloud.githubusercontent.com/assets/1020099/18914954/db9b4ade-8597-11e6-8d72-783cfd24fb99.png)

Here you can see how it works with Ukrainian localization:

![ukrainian](https://cloud.githubusercontent.com/assets/1020099/18914955/db9d95dc-8597-11e6-9c2b-6ae5cc05bc72.png)

# Example of usage
Base script for setting player russifier:
```Pawn
#include <a_samp>
#include <rustext>

static
	TextRusTD[RussifierType];

const
	Float:TEXT_BASE_X = 150.0,
	Float:TEXT_BASE_Y = 150.0,
	TEXT_RUSSIFIERS_COUNT = 7; // only Russian localizations

public OnGameModeInit()
{
	for (new i; i < TEXT_RUSSIFIERS_COUNT; i++) {
		TextRusTD[RussifierType:i] = _:TextDrawCreate(TEXT_BASE_X,
		                                              TEXT_BASE_Y + 15.0 * i,
		                                              "Я могу прочитать этот текст, это мой русификатор");
		TextDrawSetSelectable(Text:TextRusTD[RussifierType:i], 1);
		TextDrawTextSize(Text:TextRusTD[RussifierType:i], 600.0, 10.0);
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
	for (new i; i < TEXT_RUSSIFIERS_COUNT; i++) {
		SetPlayerRussifierType(playerid, RussifierType:i);
		TextDrawShowForPlayer(playerid, Text:TextRusTD[RussifierType:i]);
	}
	SelectTextDraw(playerid, 0xAA3333FF);
	return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	for (new i; i < TEXT_RUSSIFIERS_COUNT; i++) {
		if (TextRusTD[RussifierType:i] == _:clickedid) {
			SetPlayerRussifierType(playerid, RussifierType:i);
			CancelSelectTextDraw(playerid);
		}
		TextDrawHideForPlayer(playerid, Text:TextRusTD[RussifierType:i]);
	}
	return 0;
}
```

Or you can use [russifier](https://github.com/Open-GTO/russifier) library for this.
![russifier](https://user-images.githubusercontent.com/1020099/42131912-a08b08b8-7d15-11e8-93f6-aa0478d4b095.png)

# Types

```Pawn
enum RussifierType {
	RussifierType_Disabled = -1,
	RussifierType_SanLtd = 0,
	RussifierType_OneC,
	RussifierType_Rush,
	RussifierType_Unknown1,
	RussifierType_Unknown2,
	RussifierType_Unknown3,
	RussifierType_MG,
	RussifierType_Community,
	RussifierType_Ukraininan,
	RussifierType_Hungarian,
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

# Thanks

Big thanks to [urShadow](https://github.com/urShadow) for [urmem](https://github.com/urShadow/urmem) and [Pawn.RakNet](https://github.com/urShadow/Pawn.RakNet) on which based rakserver hook code.
