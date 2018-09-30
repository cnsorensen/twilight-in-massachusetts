//globals.h

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

// text colors for dialog
// FIXME: need to implement this

// plot stuff
//extern const int PLOT_COUNT;
typedef void (*Plot)();
extern Plot PLOTS[2];
//extern int PLOT_FLAGS[2];

// satifaction points
extern int SARAHG_SAT;

// OpenGL globals
extern const int SCREENWIDTH;
extern const int SCREENHEIGHT;

// other globals
extern const int DAYTIME;
extern const int NIGHTTIME;
extern int SELECT_FLAG;
extern int HOVER_FLAG; // if the cursor is hovered over a hotspot

// id's for the places, used to check current location
typedef int idPlace;
extern const idPlace idNowhere;
extern const idPlace idDowntown;
extern const idPlace idWitchesBrew;
extern const idPlace idApartmentFull;
extern const idPlace idApartmentSarah;
extern const idPlace idSalemU;

extern idPlace CURRENT_PLACE;
extern int CURRENT_TIME;
extern int TEMP_COUNT;

// number of places
extern const int PLACES_COUNT;

#endif //__GLOBALS_H__
