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
int SARAHG_SAT = 0;

// OpenGL globals
const int SCREENWIDTH = 720;
const int SCREENHEIGHT = 480;

// other globals
const int DAYTIME = 0;
const int NIGHTTIME = 1;

int SELECT_FLAG = 0;

// id's for places, used to check current location 
const idPlace idNowhere = -1;
const idPlace idDowntown = 0;
const idPlace idWitchesBrew = 1;
const idPlace idApartmentFull = 2;
const idPlace idApartmentSarah = 3;
const idPlace idSalemU = 4;
idPlace currentPlace;

// number of places
const int PLACES_COUNT = 6;
