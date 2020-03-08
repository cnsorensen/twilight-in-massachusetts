// hostspot.h

#include "globals.h"

#ifndef __HOTSPOT_H__
#define __HOTSPOT_H__

class Hotspot
{
public:

    Hotspot();
    Hotspot(int, int, int, int, idHotspot);
    Hotspot(int[5]);
    ~Hotspot();

    // FIXME: setters and getters... ugh

    idHotspot CheckHovered(int, int);

private:
    int m_x1, m_y1;
    int m_x2, m_y2;
    idHotspot m_id;
    // FIXME: cursor type maybe?
};

#endif //__HOTSPOT_H__
