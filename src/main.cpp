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
    Downtown.AddHotspot(65, 215, 175, 65, hsApartmentDoor); //apt entrance
    Downtown.AddHotspot(65, 215, 175, 65, hsWitchesBrew); //witches brew entrance
    // apartment full
    ApartmentFull.AddHotspot(480, 300, 715, 65, hsSarahBed); // sarah's bed
    ApartmentFull.AddHotspot(230, 435, 465, 230, hsWindow); // window
    ApartmentFull.AddHotspot(155, 40, 570, 0, hsLeave); // leave apartment
    // apartment sarah
    ApartmentSarah.AddHotspot(0, 75, 440, 0, hsBackUp); // back up to full apartment view
    ApartmentSarah.AddHotspot(145, 300, 195, 260, hsLight); // light on end table

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
    //glutInitWindowPosition(100, 50);
   // glutInitWindowPosition(0, 0);
    glutCreateWindow("Twilight in Massachusetts");

    glutFullScreen();

    // Indicates buffers currently enabled for color writing
    // FIXME: do I put this here? or just in display?
    //glClear(GL_COLOR_BUFFER_BIT);

    // black background
    //glClearColor(0.0, 0.0, 0.0, 0.0);
    // darpurple
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

    // initialize game
    InitGame();

    // OpenGL init
    glutInit(&argc, argv);
    InitOpenGL();

    // OpenGL/GLUT loop, NEVER TO RETURN MWUHAHAHAHAHAAAA!!!
    glutMainLoop();

    return 0;
}
