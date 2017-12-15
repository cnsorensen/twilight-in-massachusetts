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

#define CLEARSCREEN() {fprintf(stdout, "\033[H\033[J");}
#define ENTER() { char RET[3]; fprintf(stdout, "%s\nPress Enter to continue.", TC_NORM); fgets(RET, 3, stdin); }

#endif //__GLOBALS_H__
