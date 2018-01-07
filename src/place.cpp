// place.cpp

#include "place.h" 
#include <GL/freeglut.h>

Place :: Place()
: m_name("")
, m_placeColor(TC_NORM)
, m_dayBGroundFile("")
, m_nightBGroundFile("")
, m_imagePtr(NULL)
{
}

Place :: Place(const char* name, TextColor placeColor, const char* dayBGroundFile, const char* nightBGroundFile, unsigned char* imagePtr)
: m_name(name)
, m_placeColor(placeColor)
, m_dayBGroundFile(dayBGroundFile)
, m_nightBGroundFile(nightBGroundFile)
, m_imagePtr(imagePtr)
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
    if(time == NIGHTTIME) // night
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
    if(time == NIGHTTIME) // night
    {
        return m_nightBGroundFile;
    }
    else // default day
    {
        return m_dayBGroundFile;
    }
}

//Author: Sam Buss December 2001
int Place :: LoadBackground(int time)
{
    unsigned char* ImagePtr;
    const char* filename;

    // select time of day
    if(time == NIGHTTIME)
    {
        filename = m_nightBGroundFile;
    }
    else // default to day
    {
        filename = m_dayBGroundFile;
    }

    // Open for reading binary data
    FILE* infile = fopen(filename, "rb");
    if(!infile)
    {
        fprintf(stderr, "%s: unable to open file: %s\n", __PRETTY_FUNCTION__, filename);
        return -1;
    }

    // FIXME: I don't wanna check for BM... ughhhh
    int bChar = fgetc(infile);
    int mChar = fgetc(infile);
    // If starts with "BM" for "BitMap"
    if(bChar == 'B' && mChar == 'M')
    {			
        // Skip 4 fields we don't care about
        SkipChars(infile, 4 + 2 + 2 + 4 + 4);			
        // Skip one field
        SkipChars(infile, 2);					
        int bitsPerPixel = ReadShort(infile);
        // Skip 6 more fields
        SkipChars(infile, 4 + 4 + 4 + 4 + 4 + 4);		
    }

    // Allocate memory
    ImagePtr = new unsigned char[SCREENHEIGHT * GetNumBytesPerRow(SCREENWIDTH)];
    if(!ImagePtr)
    {
        fclose (infile);
        fprintf(stderr, "%s: Unable to allocate memory for %s\n", __PRETTY_FUNCTION__, filename);
        return -1;
    }

    unsigned char* cPtr = ImagePtr;
    for(int i = 0; i < SCREENHEIGHT; i++)
    {
        for(int j = 0; j < SCREENWIDTH; j++)
        {
            // blue, green, and red color value
            *(cPtr + 2) = fgetc(infile);
            *(cPtr + 1) = fgetc(infile);
            *cPtr = fgetc(infile);
            cPtr += 3;
        }

 		// Num bytes already read
        int numBytes = GetNumBytesPerRow(SCREENWIDTH);
        for(int k = 3 * SCREENWIDTH; k < numBytes; k++)
        {
			// Read and ignore padding;
            fgetc(infile);
            *(cPtr++) = 0;
        }
    }

    if(feof(infile))
    {
        fclose (infile);
        fprintf(stderr, "Premature end of file: %s.\n", filename);
        return -1;
    }

    // Close the file
    fclose(infile);

    return 1;
}

int Place :: DrawBackground(void)
{
    glRasterPos2i(0, 0);
    glDrawPixels(SCREENWIDTH, SCREENHEIGHT, GL_RGB, GL_UNSIGNED_BYTE, m_imagePtr);

    return 1;
}
// Author: Dr. John Weiss
void Place :: SkipChars(FILE* infile, int numChars)
{
    for(int i = 0; i < numChars; i++)
    {
        fgetc(infile);
    }
}

// Author: Dr. John Weiss
int Place :: GetNumBytesPerRow(int NumCols)
{
    return ((3 * NumCols + 3) >> 2) << 2;
}

// Author: Dr. John Weiss
int Place :: ReadLong(FILE* infile)
{
    unsigned char byte0, byte1, byte2, byte3;
    
    // Read bytes, low order to high order
    byte0 = fgetc(infile);
    byte1 = fgetc(infile);
    byte2 = fgetc(infile);
    byte3 = fgetc(infile);

    // Pack together
    int ret = byte3;
    ret <<= 8;
    ret |= byte2;
    ret <<= 8;
    ret |= byte1;
    ret <<= 8;
    ret |= byte0;
    return ret;
}

// Author: Dr. John Weiss
short Place :: ReadShort(FILE* infile)
{

    unsigned char lowByte, hiByte;
	
    // Read the low order byte (little endian form)
    lowByte = fgetc(infile);
    // Read the high order byte   
    hiByte = fgetc(infile);

    // Pack together
    short ret = hiByte;
    ret <<= 8;
    ret |= lowByte;
    return ret;
}
