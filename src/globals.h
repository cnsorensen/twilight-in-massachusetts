//globals.h

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

// text colors for dialog
typedef const char* TextColor;
extern TextColor TC_NORM;
extern TextColor TC_RED;
extern TextColor TC_GREEN;
extern TextColor TC_YELLOW;
extern TextColor TC_BLUE;
extern TextColor TC_PURPLE;
extern TextColor TC_CYAN;
extern TextColor TC_WHITE;
extern TextColor TextColors[8];

// functions
extern void CLEARSCREEN();
extern void ENTER();

// plot stuff
//extern const int PLOT_COUNT;
typedef void (*Plot)();
extern Plot PLOTS[5];
extern int PLOT_FLAGS[5];

// satifaction points
extern int SARAHG_SAT;

// OpenGL globals
extern const int ScreenWidth;
extern const int ScreenHeight;

#endif //__GLOBALS_H__
