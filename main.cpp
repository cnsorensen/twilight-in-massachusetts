// main.cpp

//#include "globals.h"
//#include "person.h"
//#include "persons.h"
#include "game.h"
#include "plot.h"
#include "globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
    // return value from user input
    char ret[3]; 
    char* err;

/*#ifdef DEBUG
    // printing out colors
    for(int i = 0; i < 8; i++)
    {
        fprintf(stdout, "%scolor\n", TextColors[i]);
    }
//#endif //DEBUG*/
    // initiate game
    CLEARSCREEN();

    Game TwiInMass("Twilight in Massachusetts");

    // load game if given a game file
    if(argc == 2)
    {
        fprintf(stdout, "Loading game...\n");
        TwiInMass.LoadGame(argv[1]);
    }

    // FIXME: animation?
    TwiInMass.PrintTitle(TC_YELLOW);
    
    // FIXME: Figure out savegame
    fprintf(stdout, "\n%sPress Enter to continue", TC_NORM);
    err = fgets(ret, 3, stdin);
    CLEARSCREEN();
 
    /*if(ret[0] != '\n')
    {
        return -1;
    }*/

    // start game
    TwiInMass.Run();

    return 0;
}
