// main.cpp

//#include "globals.h"
//#include "person.h"
//#include "persons.h"
#include "game.h"
#include "plot.h"
#include "callbacks.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <GL/freeglut.h>

void InitOpenGL(void)
{
    // 32-bit graphics and single buffering
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

    // windowsize, position, and title
    glutInitWindowSize(SCREENWIDTH, SCREENHEIGHT);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Twilight in Massachusetts");

    // set cursor image
    if(SELECT_FLAG)
    {
        glutSetCursor(GLUT_CURSOR_INFO);
    }
    else
    {
        glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
    }

    // black background
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // aint no callaback routines
    //redisplay window
    glutDisplayFunc(display);

    // resize
    glutReshapeFunc(reshape);

    // keyboard presses
    glutKeyboardFunc(keyboard);

    // mouse events
    glutMouseFunc(mouseclick);

    //mouse movement
    glutPassiveMotionFunc(mousedragpassive);

    //mouse pressed movement
    glutMotionFunc(mousedrag);

    return;
}


int main(int argc, char* argv[])
{
    // return value from user input
    char ret[3]; 
    char* err;

    // initiate game
    //CLEARSCREEN();

    //Game TwiInMass("Twilight in Massachusetts");

    // FIXME: load game if given a game file
    /*if(argc == 2)
    {
        fprintf(stdout, "Loading game...\n");
        TwiInMass.LoadGame(argv[1]);
    }*/

    // FIXME: animation?
    //TwiInMass.PrintTitle(TC_YELLOW);
    
    // FIXME: Figure out savegame
    //fprintf(stdout, "\n%sPress Enter to continue", TC_NORM);
    //err = fgets(ret, 3, stdin);
    //CLEARSCREEN();
 
    // start game
    //TwiInMass.Run();

    // OpenGL init
    glutInit(&argc, argv);
    InitOpenGL();

    // OpenGL/GLUT loop, NEVER TO RETURN MWUHAHAHAHAHAAAA!!!
    glutMainLoop();

    return 0;
}
