// game.cpp

#include <stdio.h>
#include <stdlib.h>

#include "plot.h"
#include "game.h"
//#include "person.h"
//#include "persons.h"
//#include "place.h"

Game :: Game()
: m_title("")
, m_textColor(TC_NORM)
{
}

Game :: Game(char* title, TextColor textColor)
: m_title(title)
, m_textColor(textColor)
{
}

Game :: ~Game()
{
}

// setters and getters
int Game :: SetTitle(char* title)
{
    m_title = title;
    return 1;
}

char* Game :: GetTitle(void)
{
    return m_title;
}

int Game :: SetTextColor(TextColor textColor)
{
    m_textColor = textColor;

    return 1;
}

TextColor Game :: GetTextColor(void)
{
    return m_textColor;
}

// functions
void Game :: Run(void)
{
    for(int i = 0; i < PLOT_COUNT; i++)
    {
        PLOTS[i]();
    }

    return;
}

int Game :: PrintTitle(void)
{
    // FIXME: add some animation?
    fprintf(stdout, "%s%s\n", m_textColor, m_title);
    return 1;
}

