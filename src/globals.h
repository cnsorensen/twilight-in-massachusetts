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

#endif //__GLOBALS_H__
