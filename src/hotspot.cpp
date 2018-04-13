// hotspot.cpp

#include "hotspot.h"

Hotspot :: Hotspot()
: m_x1(0), m_y1(0)
, m_x2(0), m_y2(0)
{
}

Hotspot :: Hotspot(int x1, int y1, int x2, int y2)
: m_x1(x1), m_y1(y1)
, m_x2(x2), m_y2(y2)
{
}

Hotspot :: Hotspot(int coords[4])
: m_x1(coords[0]), m_y1(coords[1])
, m_x2(coords[2]), m_y2(coords[3])
{
}

Hotspot :: ~Hotspot()
{
}

int Hotspot :: CheckHovered(int x, int y)
{
    // check if x is outside of the x range
    if(x < m_x1 || x > m_x2)
    {
        return 0;
    }

    // check if y is out of the y range
    if(y <= m_y1 || y > m_y2)
    {
        return 0;
    }

    // coordinate is withing both x and y range
    return 1;
}
