// plot.h

#ifndef __PLOT_H__
#define __PLOT_H__

// plot functions
extern void Plot0();
extern void Plot1();
extern void Plot2();
extern void Plot3();
extern void Plot4();

// holds the plots
const int PLOT_COUNT = 5;
typedef void (*Plot)();
extern Plot PLOTS[PLOT_COUNT];

// flags for each convo
extern int PLOT_FLAGS[PLOT_COUNT];

// misc flags

// satisfaction points
extern int SARAHG_SAT;

#endif //__PLOT_H__
