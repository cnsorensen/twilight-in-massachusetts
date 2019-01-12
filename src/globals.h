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
extern int satSarahG;

// OpenGL globals
extern int SCREENWIDTH;
extern int SCREENHEIGHT;

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

extern const int iBackgroundWidth;
extern const int iBackgroundHeight;

// id's for hotspots
typedef int idHotspot;
extern const idHotspot hsNone;
extern const idHotspot hsBackUp;
extern const idHotspot hsLeave;
// downtown hotspots
extern const idHotspot hsApartmentDoor;
extern const idHotspot hsWitchesBrew;
// apartment hotspots
extern const idHotspot hsSarahBed;
extern const idHotspot hsWindow;
// apartment sarah hotspots
extern const idHotspot hsLight;
// witches brew hotspots

// current variables
extern idPlace CURRENT_PLACE;
extern int CURRENT_TIME;
extern idHotspot CURRENT_HOTSPOT;

// FIXME: debugging flags
extern int TEMP_COUNT;
extern int TEMP_COUNT2;
extern int FULL_SIZE_FLAG;

// number of places
extern const int PLACES_COUNT;

// colors
extern const float cBlack[];
extern const float cDarkPurple[];

#endif //__GLOBALS_H__
