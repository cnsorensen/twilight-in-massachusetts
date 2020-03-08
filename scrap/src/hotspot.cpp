// hotspot.cpp

#include "hotspot.h"

#include <stdio.h>

Hotspot::Hotspot()
: m_x1(0), m_y1(0)
, m_x2(0), m_y2(0)
, m_id(-1)
{
}

Hotspot::Hotspot(int x1, int y1, int x2, int y2, idHotspot id)
: m_x1(x1), m_y1(y1)
, m_x2(x2), m_y2(y2)
, m_id(id)
{
}

Hotspot::Hotspot(int coords[5])
: m_x1(coords[0]), m_y1(coords[1])
, m_x2(coords[2]), m_y2(coords[3])
, m_id(coords[4])
{
}

Hotspot::~Hotspot()
{
}

idHotspot Hotspot::CheckHovered(int x, int y)
{
    // check if x is inside of the x range
    if(x >= m_x1 && x <= m_x2)
    {
        // check if y is inside of the y range
        if(y <= m_y1 && y >= m_y2)
        {
            return m_id;
        }
    }

    // coordinate is not within both x and y range
    return -1;
}
