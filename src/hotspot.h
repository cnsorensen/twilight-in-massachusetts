// hostspot.h

#ifndef __HOTSPOT_H__
#define __HOTSPOT_H__

class Hotspot
{
public:
    
    Hotspot();
    Hotspot(int, int, int, int);
    Hotspot(int[4]);
    ~Hotspot();

    // setters and getters... ugh

    int CheckHovered(int, int);

private:
    int m_x1, m_y1;
    int m_x2, m_y2;
};

#endif //__HOTSPOT_H__
