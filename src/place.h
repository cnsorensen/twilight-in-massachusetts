// place.h

#ifndef __PLACE_H__
#define __PLACE_H__

#include "globals.h"
#include "hotspot.h"

#include <stdlib.h>
#include <stdio.h>

class Place
{
public:

    Place();
    Place(const char*, const char*, const char*, unsigned char*,
          unsigned char*, idPlace, Hotspot*, int);
    ~Place();

    // setters and getters
    int SetName(const char*);
    const char* GetName(void);
    int SetBGroundFile(const char*, int);
    const char* GetBGroundFile(int);

    int AddHotspot(Hotspot);
    int RemoveHotspot(Hotspot);

    int LoadBackground(int);
    int DrawBackground(int);

    void GoToLocation(int);

    void CheckHotspotsHovered(int x, int y);

private:
    const char* m_name;
    const char* m_dayBGroundFile;
    const char* m_nightBGroundFile;
    unsigned char* m_imagePtrDay;
    unsigned char* m_imagePtrNight;
    idPlace m_placeId;
    Hotspot* m_hotspots;
    int m_hsCount;

    // for loading background
    void SkipChars(FILE*, int);
    int GetNumBytesPerRow(int);
    int ReadLong(FILE*);
    short ReadShort(FILE*);
};

#endif //__PLACE_H__
