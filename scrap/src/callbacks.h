/* callbacks.h */

#ifndef __CALLBACKS_H__
#define __CALLBACKS_H__

//#include "globals.h"
#include "places.h"

// function prototypes
void display(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void mouseclick(int button, int state, int x, int y);
void mousedragpassive(int x, int y);
void mousedrag(int x, int y);

// location
extern Place* pCurrentLocation;

#endif //__CALLBACKS_H__
