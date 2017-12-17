// game.h

#ifndef __GAME_H__
#define __GAME_H__

#include "globals.h"

class Game
{
public: // functions

    Game();
    Game(char*);
    ~Game();

    // setters and getters
    int SetTitle(char*);
    char* GetTitle(void);

    // functions
    // move places()?
    // moveTo(place)?
    void Run();
    int PrintTitle(TextColor);
    void LoadGame(char*);
    void SaveGame(void);
 
public: // variables
    // should I include arrays of people and places?
    // i need something to hold plot line and dialogs??    

private:
    char* m_title;
};

#endif //__GAME_H__
