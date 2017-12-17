// place.cpp

#include "place.h" 
#include <stdio.h>
#include <stdlib.h>


Place :: Place()
: m_name("")
, m_placeColor(TC_NORM)
{
}

Place :: Place(const char* name, TextColor placeColor)
: m_name(name)
, m_placeColor(placeColor)
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

void Place :: PrintPlaceDescription(const char* description)
{
    fprintf(stdout, "%s\n%s\n", m_placeColor, description);
    return;
}
