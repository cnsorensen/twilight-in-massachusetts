// place.h

#ifndef __PLACE_H__
#define __PLACE_H__

#include "globals.h"

class Place
{
public:

    Place();
    Place(const char*, TextColor, const char*, const char*);
    ~Place();

    // setters and getters
    int SetName(const char*);
    const char* GetName(void);
    int SetPlaceColor(TextColor);
    TextColor GetPlaceColor(void);
    int SetBGroundFile(const char*, int);
    const char* GetBGroundFile(int);

    void PrintPlaceDescription(const char*);

private:
    const char* m_name;
    TextColor m_placeColor;
    const char* m_dayBGroundFile;
    const char* m_nightBGroundFile;
};

#endif //__PLACE_H__
