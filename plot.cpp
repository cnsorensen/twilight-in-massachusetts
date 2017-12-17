// plot.cpp

#include "game.h"
#include "plot.h"
#include "persons.h"
#include "places.h"

#include <stdio.h>
#include <stdlib.h>

// plot variables
//int PLOT_FLAGS[5] = {0};
//int SARAHG_SAT = 0;

Plot PLOTS[5] = {Plot0, Plot1, Plot2, Plot3, Plot4};

void Plot0()
{
    // if the plot is being repeated
    if(PLOT_FLAGS[0] == 1)
    {
        return;
    }

    //Intro - Christine's letter to Stevie
    char ret[2];

    // FIXME: I want to type it out but for development let's just print if out
    ChristineS.Speak("Hey Stevie,\n\nIt sucks that you couldn't come to Salem with me. \
I found some random chick to take your place in our apartment, Sarah Goode. \
She got me a job at the coffee shop she works at, Witches Brew.\
\n\nI have a weird feeling about this town with and its history of the Salem Witch Trials \
(we probably should've paid attention to US History last year haha). \
\n\nWell, I hope you can come visit soon!\nSincerely, Christine", 0, 0, 0);

    ENTER();   
    CLEARSCREEN();

    PLOT_FLAGS[0] = 1;

    return;
}

/*
Christine's first conversation with her new roommate Sarah
    in their apartment.
*/
void Plot1()
{
    char ret1[3];
    char ret2[3];
    int ret_valid;
    char* err;

    // if the plot is being repeated
    if(PLOT_FLAGS[1] == 1)
    {
        return;
    }

    // FIXME: Christine walks into her aparment and sees
    //        Sarah sitting on the bed opposite of what's
    //        assumed Christine's reading a textbook.
    Apartment.PrintPlaceDescription("Christine walks into her new studio apartment. She sees a girl sitting on the bed by the window reading a text book.");
    
    ENTER();
    CLEARSCREEN();


    do
    {
        ret_valid = -1;
        SarahG.Speak("Hey, you must be Christine! I'm your new roommate Sarah.\n", 1, 0, 0);

        // reply1
        ChristineS.Speak("Hi Sarah. What are you reading?", 0, 0, 1);

        // reply2
        ChristineS.Speak("I'm guessing this is my bed by the wall?", 0, 0, 2);

        fprintf(stdout, "\n%sChoose one: ", TC_NORM);   
        err = fgets(ret1, 3, stdin);
        CLEARSCREEN();
    
        if(ret1[0] == '2')
        {
            SarahG.Speak("Oh right, I hope you don't mind I picked the one by the window.", 0, 0, 0);
            SARAHG_SAT--; 
            ENTER();
            CLEARSCREEN();
            ret_valid = 0;
        }
        else if(ret1[0] == '1')
        {
            SARAHG_SAT++;
            ret_valid = 0;
        }

    }while(ret_valid == -1);

    do
    {
        ret_valid = -1;
        SarahG.Speak("I've been busy studying the Salem Witch Trials for my history class.", 0, 0, 0);
    
        // reply1
        ChristineS.Speak("Shouldn't you know all about it already? I mean, you live here, don't you?", 0, 0, 1);

        // reply2
        ChristineS.Speak("I really don't know much about the trials.", 0, 0, 2);

        fprintf(stdout, "\n%sChoose one: ", TC_NORM);   
        err = fgets(ret1, 3, stdin);
        CLEARSCREEN();

        if(ret1[0] == '2')
        {
            do
            {
                SarahG.Speak("I can teach you, that is if you're interested.", 0, 0, 0);

                // reply1
                ChristineS.Speak("Umm, I'm good. Thanks though.", 0, 0, 1);

                // reply2
                ChristineS.Speak("Sure, maybe after my first shift at the Witches Brew?", 0, 0, 2);

                fprintf(stdout, "\n%sChoose one: ", TC_NORM);   
                err = fgets(ret2, 3, stdin);
                CLEARSCREEN();

                if(ret2[0] == '1')
                {
                    ret_valid = 0;
                }
                else if(ret2[0] == '2')
                {
                    SARAHG_SAT++;
                    ret_valid = 0;
                }
            }while(ret_valid == -1);

            ret_valid = 0;
        }

        if(ret1[0] == '1' || ret2[0] == '1')
        {
            SarahG.Speak("Look, if you're going to not take this seriously, then don't say anything at all.", 0, 0, 0);
            SARAHG_SAT -= 2;

            ENTER();
            CLEARSCREEN();

            ret_valid = 0;
        }

    }while(ret_valid == -1);

    SarahG.Speak("It's time for your first shift anyway. Let's go.", 0, 0, 0); 

    ENTER();
    CLEARSCREEN(); 
    // debugging
    //printf("%d\n", SARAHG_SAT);
 
    // mark this plot complete
    PLOT_FLAGS[1] = 1;

    return;
}

void Plot2()
{
    char* err;
    char ret1[3];
    char ret2[3];    
    int ret_valid;

    // if the plot is being repeated 
    if(PLOT_FLAGS[2] == 1)
    {
        return;
    }

    // debugging
    fprintf(stdout, "Plot2\n");

    ENTER();
    CLEARSCREEN();

    // mark this plot complete
    PLOT_FLAGS[2] = 1;

    //SaveGame();

    return;
}

void Plot3()
{
    char ret1[3];
    char ret2[3];    

    // if the plot has been repeated
    if(PLOT_FLAGS[3] == 1)
    {
        return;
    }

    // debugging
    fprintf(stdout, "Plot3\n");

    ENTER();
    CLEARSCREEN();

    // mark this plot complete
    PLOT_FLAGS[3] = 1;

    return;
}

void Plot4()
{
    char ret1[3];
    char ret2[3];    

    // if the plot is being repeated
    if(PLOT_FLAGS[4] == 1)
    {
        return;
    }

    // debugging
    fprintf(stdout, "Plot4\n");

    ENTER();
    CLEARSCREEN();

    // mark this plot complete
    PLOT_FLAGS[4] = 1;

    return;
}



