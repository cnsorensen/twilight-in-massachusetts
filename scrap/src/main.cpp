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

// Loads all backgrounds, characters, objects, and etc...
void InitGame(void)
{
    // initialize values

    // FIXME: should I be loading *everything* at startup?
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
    // downtown
    Downtown.AddHotspot(290, 460, 525, 145, hsApartmentDoor); //apt entrance
    Downtown.AddHotspot(1000, 480, 1360, 80, hsWitchesBrew); //witches brew entrance
    // apartment full
    ApartmentFull.AddHotspot(1310, 580, 1660, 150, hsSarahBed); // sarah's bed
    ApartmentFull.AddHotspot(660, 860, 1155, 470, hsWindow); // window
    ApartmentFull.AddHotspot(510, 45, 1390, 0, hsLeave); // leave apartment
    // apartment sarah
    ApartmentSarah.AddHotspot(445, 40, 1420, 0, hsBackUp); // back up to full apartment view
    ApartmentSarah.AddHotspot(475, 620, 610, 500, hsLight); // light on end table

    // Load objects

    return;
}

void InitOpenGL(void)
{
    // 32-bit graphics and single buffering
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    // 32-bit graphs and double buffering
    //glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    // windowsize, position, and title
    //glutInitWindowSize(SCREENWIDTH, SCREENHEIGHT);
    //glutInitWindowPosition(0, 0);
    glutCreateWindow("Twilight in Massachusetts");

    glutFullScreen();

    // Indicates buffers currently enabled for color writing
    // FIXME: do I put this here? or just in display?
    //glClear(GL_COLOR_BUFFER_BIT);

    // FIXME: do I do this here or in display?
    // black background
    //glClearColor(0.0, 0.0, 0.0, 0.0);
    // dark purple background
    glClearColor(0.2, 0.0, 0.2, 0.0);

    //redisplay window
    glutDisplayFunc(display);

    // FIXME: I may need this...
    //glutIdleFunc(display);

    // resize
    glutReshapeFunc(reshape);

    // keyboard presses
    glutKeyboardFunc(keyboard);

    // mouse events
    glutMouseFunc(mouseclick);

    // mouse movement
    glutPassiveMotionFunc(mousedragpassive);

    // mouse pressed movement
    glutMotionFunc(mousedrag);

    return;
}

int main(int argc, char* argv[])
{
    // FIXME: load game if given a game file

    // load backgrounds and etc for the game
    InitGame();

    // OpenGL init
    glutInit(&argc, argv);
    InitOpenGL();

    // OpenGL/GLUT loop, NEVER TO RETURN MWUHAHAHAHAHAAAA!!!
    glutMainLoop();

    return 0;
}
