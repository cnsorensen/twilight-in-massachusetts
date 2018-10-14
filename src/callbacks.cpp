/* callbacks.cpp */

#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include "callbacks.h"
#include "places.h"

// locations
// FIXME: should i put the other current globals here instead?
Place CurrentLocation;

// aint no callabacks gurl
/**********************************************************************
                            display
**********************************************************************
display provides OpenGL
**********************************************************************/
void display(void)
{
    // background color
    // FIXME: Does this go here?
    glClearColor(0.2, 0.0, 0.2, 0.0);

    // clear the display
    glClear(GL_COLOR_BUFFER_BIT);

    //FIXME: debugging
    // Full screen is Width: 1920, Height: 950
	// Takes a second to get to that size
    if(TEMP_COUNT == 0)
    {
        printf("Current: %d - Downtown: %d\n", CURRENT_PLACE, idDowntown);
        printf("Width %d, Height %d\n", glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        TEMP_COUNT++;
    }

    // draw background based on current location
    // Maybe draw background based on size from the center? 
    /*
    if(CURRENT_PLACE == idDowntown)
    {
        Downtown.GoToLocation(CURRENT_TIME);
        // FIXME: do I do the redisplay for all of them?
        //glutPostRedisplay();
    }
    else if(CURRENT_PLACE == idApartmentFull)
    {
        ApartmentFull.GoToLocation(CURRENT_TIME);
    }
    else if(CURRENT_PLACE == idApartmentSarah)
    {
        ApartmentSarah.GoToLocation(CURRENT_TIME);
    }
    */

    // should do an implicit glFlush()
    // FIXME: what do you mean my implicit?
    //glutSwapBuffers(); // for double buffering
    glFlush(); // single buffering

    return;
}

/**********************************************************************
                            dragDraw
**********************************************************************
**********************************************************************/
void dragDraw()
{
}

/**********************************************************************
                            reshape
**********************************************************************
reshape takes a height and width and uses openGL to redraw the window
for the user to fit the new dimentions.

parameters:     w - the desired window width
                h - the desired window height
**********************************************************************/
void reshape(int w, int h)
{
    // nice try, bucko. No reshaping window.
    // FIXME: i need full screen and i need it now 867-cash-now
    //glutReshapeWindow(SCREENWIDTH, SCREENHEIGHT);

    // how to project 3-D scene onto 2-D
    // use an orthographic projection
    glMatrixMode(GL_PROJECTION);
    // Initailze transformation matrix
    glLoadIdentity();
    // Make OpenGL coordinates
    gluOrtho2D(0.0, w, 0.0, h);
    // the same as the screen coordinates
    glViewport(0, 0, w, h);
}

/**********************************************************************
                            keyboard
**********************************************************************
keyboard begins by compensating for the reverse y coordinate system
within openGL. It then determines which key on the keyboard was pressed
by the user.

Both 'q' and the Escape Key will close the program.

parameters:     key - the character value of the key pressed
                x - the x value of the selected coordinate
                y - the y value of the selected coordinate
**********************************************************************/
void keyboard(unsigned char key, int x, int y)
{
    //correct for upside-down screen coordinates
    //y = SCREENHEIGHT - y;

    switch(key)
    {
        // Escape or 'q' quits program
        case 'q':
        case 27: //escape key
            exit(0);
            break;
        default:
            // refresh the screen for any other key presses
            glutPostRedisplay();
            break;
    }
}

/**********************************************************************
                            mouseclick
**********************************************************************
mouseclick begins by compensating for the reverse y coordinate
system within openGL. It then determines whether the left or right
mouse button was pressed by the user. Next it determines the state of
the button, whether it has been pressed down or release.

If the left button is pressed down, it evaluates the location of the
press...

If the right button is pressed down it evaluates the location of the
press

parameters:     button - the value of the button that was clicked
                state - the state of the button
                x - the x value of the selected coordinate
                y - the y value of the selected coordinate
**********************************************************************/
void mouseclick(int button, int state, int x, int y)
{
    // FIXME: placeholder for empty switch cases
    int greeneggs;

    //correct for upside-down screen coordinates
    //y = SCREENHEIGHT - y;

    // handle mouse click events
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            TEMP_COUNT = 0;
            // press
            if(state == GLUT_DOWN)
            {
                // FIXME: this is for debugging right now
                printf("x:%d, y:%d\n", x, y);

                // FIXME: do some sort of event here
                if(HOVER_FLAG)
                {
                    printf("Flag is hovered - %d\n", CURRENT_PLACE);
                    if(CURRENT_PLACE == idDowntown)
                    {
                        if(CURRENT_HOTSPOT == hsApartmentDoor)
                        {
                            CURRENT_PLACE = idApartmentFull;
                        }
                        else if(CURRENT_HOTSPOT == hsWitchesBrew)
                        {
                            //FIXME: need to implement
                            //CURRENT_PLACE = idWitchesBrew;
                            greeneggs = 2;
                        }
                    }
                    else if(CURRENT_PLACE == idWitchesBrew)
                    {
                        greeneggs = 2;
                    }
                    else if(CURRENT_PLACE == idApartmentFull)
                    {
                        if(CURRENT_HOTSPOT == hsSarahBed)
                        {
                            CURRENT_PLACE = idApartmentSarah;
                        }
                        else if(CURRENT_HOTSPOT == hsWindow)
                        {
                            if(CURRENT_TIME == DAYTIME)
                            {
                                CURRENT_TIME = NIGHTTIME;
                            }
                            else
                            {
                                CURRENT_TIME = DAYTIME;
                            }
                        }
                        else if(CURRENT_HOTSPOT == hsLeave)
                        {
                            CURRENT_PLACE = idDowntown;
                        }
                    }
                    else if(CURRENT_PLACE == idApartmentSarah)
                    {
                        if(CURRENT_HOTSPOT == hsBackUp)
                        {
                            CURRENT_PLACE = idApartmentFull;
                        }
                        else if(CURRENT_HOTSPOT == hsLight)
                        {
                            if(CURRENT_TIME == DAYTIME)
                            {
                                CURRENT_TIME = NIGHTTIME;
                            }
                            else
                            {
                                CURRENT_TIME = DAYTIME;
                            }
                        }
                    }
                    else if(CURRENT_PLACE == idSalemU)
                    {
                        greeneggs = 2;
                    }
                }
            }
            // release
            else if(state == GLUT_UP)
            {
                // I do not like them, Sam-I-Am
                greeneggs = 1;
            }
            break;
        case GLUT_RIGHT_BUTTON:
            // press
            if(state == GLUT_DOWN)
            {
                greeneggs = 1;
            }
            // release
            else if(state == GLUT_UP)
            {
                greeneggs = 1;
            }
            break;
        default:
            break;
    }

    //refresh the display
    glutPostRedisplay();
}

/* when the mouse isn't pressed down */
void mousedragpassive(int x, int y)
{
    // FIXME: placeholder for between if's
    int greeneggs;

    // correct the y coordinate
    //y = SCREENHEIGHT - y;

    // search for hotspots
    // change cursor icon based on where the cursor is currently located
    // FIXME: change which type of cursor depending on hotspot
    if(CURRENT_PLACE == idDowntown)
    {
        Downtown.CheckHotspotsHovered(x, y);

        if(HOVER_FLAG)
        {
            glutSetCursor(GLUT_CURSOR_INFO);
        }
        else
        {
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        }
    }
    else if(CURRENT_PLACE == idApartmentFull)
    {
        ApartmentFull.CheckHotspotsHovered(x, y);

        if(HOVER_FLAG)
        {
            glutSetCursor(GLUT_CURSOR_INFO);
        }
        else
        {
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        }
    }
    else if(CURRENT_PLACE == idApartmentSarah)
    {
        ApartmentSarah.CheckHotspotsHovered(x, y);

        if(HOVER_FLAG)
        {
            glutSetCursor(GLUT_CURSOR_INFO);
        }
        else
        {
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        }

    }
    else if(CURRENT_PLACE == idWitchesBrew)
    {
        greeneggs = 2;
    }
    else if(CURRENT_PLACE == idSalemU)
    {
        greeneggs = 2;
    }
    else
    {
        greeneggs = 2;
    }

    // refresh display
    glutPostRedisplay();
}

/* when the mouse button is held down */
void mousedrag(int x, int y)
{
    // correct the y coordinate
    //y = SCREENHEIGHT - y;

    // refresh display
    glutPostRedisplay();
}
