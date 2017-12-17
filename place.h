// place.h

#ifndef __PLACE_H__
#define __PLACE_H__

#include "globals.h"

class Place
{
public:

    Place();
    Place(const char*, TextColor);
    ~Place();

    // setters and getters
    int SetName(const char*);
    const char* GetName(void);
    int SetPlaceColor(TextColor);
    TextColor GetPlaceColor(void);

    void PrintPlaceDescription(const char*);

private:
    const char* m_name;
    TextColor m_placeColor;
    // should we have a place type or something?
    // need some more characteristics
};

#endif //__PLACE_H__
