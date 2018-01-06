// place.cpp

#include "place.h" 
#include <stdio.h>
#include <stdlib.h>


Place :: Place()
: m_name("")
, m_placeColor(TC_NORM)
, m_dayBGroundFile("")
, m_nightBGroundFile("")
{
}

Place :: Place(const char* name, TextColor placeColor, const char* dayBGroundFile, const char* nightBGroundFile)
: m_name(name)
, m_placeColor(placeColor)
, m_dayBGroundFile(dayBGroundFile)
, m_nightBGroundFile(nightBGroundFile)
{
}

Place :: ~Place()
{
}

// setters and getters

int Place :: SetName(const char* name)
{
    m_name = name;
    return 1;
}

const char* Place :: GetName(void)
{
    return m_name;
}

int Place :: SetPlaceColor(TextColor placeColor)
{
    m_placeColor = placeColor;
    return 1;
}

TextColor Place :: GetPlaceColor(void)
{
    return m_placeColor;
}

int Place :: SetBGroundFile(const char* bGroundFile, int time)
{
    if(time == 1) // night
    {
        m_dayBGroundFile = bGroundFile;
        return 1;
    }
    else // default day
    {
        m_nightBGroundFile = bGroundFile;
        return 1;
    }
}

const char* Place :: GetBGroundFile(int time)
{
    if(time == 1) // night
    {
        return m_nightBGroundFile;
    }
    else // default day
    {
        return m_dayBGroundFile;
    }
}

