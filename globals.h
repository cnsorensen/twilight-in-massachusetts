//globals.h

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

// text colors for dialog
typedef char* TextColor;
extern TextColor TC_NORM;
extern TextColor TC_RED;
extern TextColor TC_GREEN;
extern TextColor TC_YELLOW;
extern TextColor TC_BLUE;
extern TextColor TC_PURPLE;
extern TextColor TC_CYAN;
extern TextColor TC_WHITE;
extern TextColor TextColors[8];

extern void CLEARSCREEN();
extern void ENTER();

//extern const int PLOT_COUNT;
typedef void (*Plot)();
extern Plot PLOTS[5];

extern int PLOT_FLAGS[5];

extern int SARAHG_SAT;

#endif //__GLOBALS_H__
