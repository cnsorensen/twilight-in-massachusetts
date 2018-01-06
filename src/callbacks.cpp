/* callbacks.cpp */

#include <GL/freeglut.h>
#include "callbacks.h"
#include "places.h"

// locations
Place CurrentLocation;

// aint no callabacks gurl
/**********************************************************************
                            display
**********************************************************************
display provides OpenGL
**********************************************************************/
void display( void )
{
    // clear the display
    glClear( GL_COLOR_BUFFER_BIT );

    // draw background
    //glTexImage2D(GL_TEXTURE_RECTANGLE, 0, ScreenWidth, ScreenHeight, 0, GL_BGRA_INTEGER, GL_BYTE,

    // should do an implicit glFlush()
    glutSwapBuffers();
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
    glutReshapeWindow(ScreenWidth, ScreenHeight);

    // how to project 3-D scene onto 2-D
    // use an orthographic projection
    //glMatrixMode(GL_PROJECTION);
    // Initailze transformation matrix
    //glLoadIdentity();
    // Make OpenGL coordinates
    //gluOrtho2D(0.0, w, 0.0, h);
    // the same as the screen coordinates
    //glViewport(0, 0, w, h);   
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
    y = ScreenHeight - y;

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
    y = ScreenHeight - y;

    // handle mouse click events
    switch( button )
    {
    // left button: create objects, select border color, select shape
        case GLUT_LEFT_BUTTON:
            // press
            if( state == GLUT_DOWN )
            {    
                greeneggs = 1;
            }
            // release
            else if( state == GLUT_UP )
            {
                greeneggs = 2;
            }
            break;
        // right button: select fill color
        case GLUT_RIGHT_BUTTON:
            // press
            if( state == GLUT_DOWN )
            {
                greeneggs = 1;
            }
            // release
            else if( state == GLUT_UP )
            {
                greeneggs = 1;
            }
            break;
    }
    
    //refresh the display
    glutPostRedisplay();
}

/* when the mouse isn't pressed down */
void mousedragpassive( int x, int y )
{
    // correct the y coordinate
    y = ScreenHeight - y;

    // refresh display
    glutPostRedisplay();
}

/* when the mouse button is held down */
void mousedrag( int x, int y )
{
    // correct the y coordinate
    y = ScreenHeight - y;
    
    // refresh display
    glutPostRedisplay();
}
