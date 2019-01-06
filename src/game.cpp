// game.cpp

#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "plot.h"

//#include "person.h"
//#include "persons.h"
//#include "place.h"

Game :: Game()
: m_title("")
{
}

Game :: Game(const char* title)
: m_title(title)
{
}

Game :: ~Game()
{
}

// setters and getters
int Game :: SetTitle(const char* title)
{
    m_title = title;
    return 1;
}

const char* Game :: GetTitle(void)
{
    return m_title;
}

// functions
void Game :: Run()
{
    for(int i = 0; i < 2; i++)
    {
        PLOTS[i]();
    }

    return;
}

void Game :: LoadGame(const char* fileName)
{
    int val;
    FILE* gameFile;
    int scanCount;

    // open file
    gameFile = fopen(fileName, "r");

    // check if file opened
    if(!gameFile)
    {
        fprintf(stdout, "%s - Unable to open file %s", __PRETTY_FUNCTION__,
                fileName);
        return;
    }

    // grab values from file
    val = -1;
    for(int i = 0; i < 2; i++)
    {
        scanCount = fscanf(gameFile, "%d", &val);

        if(scanCount != 1)
        {
            fprintf(stdout, "%s - Unsuccessful scanf\n", __PRETTY_FUNCTION__);
        }

        //PLOT_FLAGS[i] = val;

        if(feof(gameFile))
        {
            fprintf(stdout, "%s - Invalid file %s", __PRETTY_FUNCTION__,
                    fileName);
            return;
        }

        // debugging
        fprintf(stdout, "%d ", val);
    }

    // get satisfaction points
    scanCount = fscanf(gameFile, "%d", &val);
    if(scanCount != 1)
    {
        fprintf(stdout, "%s - Unsuccessful scanf\n", __PRETTY_FUNCTION__);
    }

    satSarahG = val;

    // FIXME: debugging
    fprintf(stdout, "%d\n", val);

    // close gamefile
    fclose(gameFile);

    return;
}

void Game :: SaveGame(void)
{
    //int i;
    int val;
    FILE* gameFile;

    // open file
    gameFile = fopen("file.service", "w");

    // check if file opened
    if(!gameFile)
    {
        fprintf(stdout, "%s - Unable to open file %s", __PRETTY_FUNCTION__, "gamesave.txt");
        return;
    }

    // grab values from file
    val = -1;
    for(int i = 0; i < 2; i++)
    {
        //val = PLOT_FLAGS[i];
        fprintf(gameFile, "%d\n", val);
    }

    // put sat points
    satSarahG = val;
    fprintf(gameFile, "%d\n", val);

    // debugging
    fprintf(stdout, "%d\n", val);

    // close gamefile
    fclose(gameFile);

    return;
}
