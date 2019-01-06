// place.h

#ifndef __PLACE_H__
#define __PLACE_H__

#include "globals.h"
#include "hotspot.h"

#include <stdlib.h>
#include <stdio.h>
#include <vector>

class Place
{
public:

    Place();
    Place(const char*, const char*, const char*, unsigned char*,
          unsigned char*, idPlace, std::vector<Hotspot>);
    ~Place();

    // setters and getters
    int SetName(const char*);
    const char* GetName(void);
    int SetBGroundFile(const char*, int);
    const char* GetBGroundFile(int);
    unsigned char* GetImagePtrDay(void);
    unsigned char* GetImagePtrNight(void);

    int AddHotspot(Hotspot);
    int AddHotspot(int, int, int, int, idHotspot);
    int RemoveHotspot(Hotspot);

    int LoadBackground(int);

    void GoToLocation(int);
    idHotspot CheckHotspotsHovered(int x, int y);

private:
    const char* m_name;
    const char* m_dayBGroundFile;
    const char* m_nightBGroundFile;
    unsigned char* m_imagePtrDay;
    unsigned char* m_imagePtrNight;
    idPlace m_placeId;
    std::vector<Hotspot> m_hotspots;

    // for loading background
    void SkipChars(FILE*, int);
    int GetNumBytesPerRow(int);
    int ReadLong(FILE*);
    short ReadShort(FILE*);
};

#endif //__PLACE_H__
