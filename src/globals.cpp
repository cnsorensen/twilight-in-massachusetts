// globals.cpp

#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// text colors for dialog
// FIXME: need to do this

// plot stuff
//const int PLOT_COUNT;
// flags for each convo
int PLOT_FLAGS[5] = {0};

// satisfaction points for each character
int satSarahG = 0;

// OpenGL globals
const int SCREENWIDTH = 720;
const int SCREENHEIGHT = 480;

// other globals
const int DAYTIME = 0;
const int NIGHTTIME = 1;

int SELECT_FLAG = 0;
int HOVER_FLAG = 0; // if the cursor is hovered over a hotspot
int TEMP_COUNT = 0;

// id's for places, used to check current location
const idPlace idNowhere = -1;
const idPlace idDowntown = 1;
const idPlace idWitchesBrew = 0;
const idPlace idApartmentFull = 2;
const idPlace idApartmentSarah = 3;
const idPlace idSalemU = 4;

// id's for hotspots
const idHotspot hsNone = -1;
const idHotspot hsBackUp = 0;
const idHotspot hsLeave = 1;
// downtown
const idHotspot hsApartmentDoor = 11;
const idHotspot hsWitchesBrew = 12;
// apartment hotspots
const idHotspot hsSarahBed = 21;
const idHotspot hsWindow = 22;
// apartment sarah hotspots
const idHotspot hsLight = 31;
// witches brew hotspots

// current globals
idPlace CURRENT_PLACE = idDowntown;//idNowhere;
idHotspot CURRENT_HOTSPOT = hsNone;
int CURRENT_TIME = DAYTIME;

// number of places
const int PLACES_COUNT = 6;
