// main.cpp

//#include "globals.h"
//#include "person.h"
//#include "persons.h"
#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;


int main(int argc, char* argv[])
{
    // return value from user input
    char ret[2]; 

/*#ifdef DEBUG
    for(int i = 0; i < 8; i++)
    {
        fprintf(stdout, "%scolor\n", TextColors[i]);
    }
    Person JonDoe("Jon", "Doe", TC_RED, 69);
    fprintf(stdout, "%s%s %s: I'm %d\n", JonDoe.GetTextColor(),
            JonDoe.GetFirstName(), JonDoe.GetLastName(), 
            JonDoe.GetAge());
    ChristineS.Speak("Hello world!!", 0);
    StevieN.Speak("Hey yall", 1);
    fprintf(stdout, "%d\n", ChristineS.GetAge());
//#endif //DEBUG*/

    // initiate game
    CLEARSCREEN();
    Game TwiInMass("Twilight in Massechusetts", TC_YELLOW);
    // FIXME: animation?
    TwiInMass.PrintTitle();
    
    // FIXME: Figure out savegame password
    fprintf(stdout, "\n%sPress Enter to continue", TC_NORM);
    fgets(ret, 3, stdin);
    CLEARSCREEN();
 
    /*if(ret[0] != '\n')
    {
        return -1;
    }*/

    // start game
    TwiInMass.Run();

    return 0;
}
