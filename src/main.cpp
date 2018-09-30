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

/*
Loads all backgrounds, characters, objects, and etc...
*/
void InitGame(void)
{
    // initialize values

    // Load all backgrounds
    Downtown.LoadBackground(DAYTIME);
    Downtown.LoadBackground(NIGHTTIME);
    //WitchesBrew.LoadBackground(DAYTIME);
    //WitchesBrew.LoadBackground(NIGHTTIME);
    ApartmentFull.LoadBackground(DAYTIME);
    ApartmentFull.LoadBackground(NIGHTTIME);
    ApartmentSarah.LoadBackground(DAYTIME);
    ApartmentSarah.LoadBackground(NIGHTTIME);
    //SalemU.LoadBackground(DAYTIME);
    //SalemU.LoadBackground(NIGHTTIME);

    // Load characters

    // Load hotspots
    Downtown.AddHotspot(65, 215, 175, 65);

    // Load objects

    return;
}

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
    //glutIdleFunc(display); // do i need this?

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
    // FIXME: load game if given a game file

    // initialize game
    InitGame();

    // OpenGL init
    glutInit(&argc, argv);
    InitOpenGL();

    // OpenGL/GLUT loop, NEVER TO RETURN MWUHAHAHAHAHAAAA!!!
    glutMainLoop();

    return 0;
}
