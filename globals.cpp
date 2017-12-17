// globals.cpp

#include "globals.h"
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
//#include <string.h>

using namespace std;

// text colors for dialog
TextColor TC_NORM = "\x1B[0m";
TextColor TC_RED = "\x1B[31m";
TextColor TC_GREEN = "\x1B[32m";
TextColor TC_YELLOW = "\x1B[33m";
TextColor TC_BLUE = "\x1B[34m";
TextColor TC_PURPLE = "\x1B[35m";
TextColor TC_CYAN = "\x1B[36m";
TextColor TC_WHITE = "\x1B[37m";

TextColor TextColors[8] = {TC_NORM, TC_RED, TC_GREEN, TC_YELLOW, 
                           TC_BLUE, TC_PURPLE, TC_CYAN, TC_WHITE};

//const int PLOT_COUNT;

// flags for each convo
int PLOT_FLAGS[5] = {0};

// satisfaction points
int SARAHG_SAT = 0;

void CLEARSCREEN()
{
    fprintf(stdout, "\033[H\033[J");

    return;
}

void ENTER()
{
    char RET[3];
    fprintf(stdout, "%s\nPress Enter to continue.", TC_NORM); 
    fgets(RET, 3, stdin); 

    return;
}