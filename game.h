// game.h

#ifndef __GAME_H__
#define __GAME_H__

#include "globals.h"

class Game
{
public: // functions

    Game();
    Game(char*, TextColor);
    ~Game();

    // setters and getters
    int SetTitle(char*);
    char* GetTitle(void);
    int SetTextColor(TextColor);
    TextColor GetTextColor(void);

    // functions
    // move places()?
    // moveTo(place)?
    void Run(void);
    int PrintTitle(void);
    
public: // variables
    // should I include arrays of people and places?
    // i need something to hold plot line and dialogs??    

private:
    char* m_title;
    TextColor m_textColor;
};

#endif //__GAME_H__
