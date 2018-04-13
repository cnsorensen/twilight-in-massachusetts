// place.h

#ifndef __PLACE_H__
#define __PLACE_H__

#include "globals.h"

#include <stdlib.h>
#include <stdio.h>

class Place
{
public:

    Place();
    Place(const char*, const char*, const char*, unsigned char*);
    ~Place();

    // setters and getters
    int SetName(const char*);
    const char* GetName(void);
    int SetBGroundFile(const char*, int);
    const char* GetBGroundFile(int);

    void PrintPlaceDescription(const char*);
    int LoadBackground(int);
    int DrawBackground(void);

private:
    const char* m_name;
    const char* m_dayBGroundFile;
    const char* m_nightBGroundFile;
    unsigned char* m_imagePtr;
    // hotspots


    // for loading background
    void SkipChars(FILE*, int);
    int GetNumBytesPerRow(int);
    int ReadLong(FILE*);
    short ReadShort(FILE*);
};

#endif //__PLACE_H__
