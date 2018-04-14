// place.cpp

#include "place.h" 
#include <GL/freeglut.h>

Place :: Place()
: m_name("")
, m_dayBGroundFile("")
, m_nightBGroundFile("")
, m_imagePtrDay(NULL)
, m_imagePtrNight(NULL)
, m_placeId(idNowhere)
, m_hotspots(std::vector<Hotspot>())
{
}

Place :: Place(const char* name, const char* dayBGroundFile, 
               const char* nightBGroundFile, unsigned char* imagePtrDay,
               unsigned char* imagePtrNight, idPlace placeId, std::vector<Hotspot> hotspots)
: m_name(name)
, m_dayBGroundFile(dayBGroundFile)
, m_nightBGroundFile(nightBGroundFile)
, m_imagePtrDay(imagePtrDay)
, m_imagePtrNight(imagePtrNight)
, m_placeId(placeId)
, m_hotspots(hotspots)
{
}

Place :: ~Place()
{
    if(m_imagePtrDay != NULL)
    {
        delete m_imagePtrDay;
    }
    if(m_imagePtrNight != NULL)
    {
        delete m_imagePtrNight;
    }
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

// adds an existing hotspot to the list
int Place :: AddHotspot(Hotspot h)
{
    std::vector<Hotspot>::iterator it;
    it = m_hotspots.begin();

    m_hotspots.push_back(h);
 
	return 1;
}

// creates new hotspot before adding to the list of hotspots
int Place :: AddHotspot(int x1, int y1, int x2, int y2)
{
    Hotspot t_hs(x1, y1, x2, y2);

    std::vector<Hotspot>::iterator it;
    it = m_hotspots.begin();

    m_hotspots.push_back(t_hs);
 
    return 1;
}

int Place :: RemoveHotspot(Hotspot h)
{
    return -1;
}

void Place :: GoToLocation(int time)
{
    DrawBackground(time);
    currentPlace = m_placeId;

    return;
}

void Place :: CheckHotspotsHovered(int x, int y)
{
	// hotspots iterator
    std::vector<Hotspot>::iterator it;

    // check to see if cursor is hovered over a hotspot
    // if so, set the flag for hover so the cursor symbol can change
    for(it = m_hotspots.begin(); it != m_hotspots.end(); it++)
    {
        if(it->CheckHovered(x, y))
        {
            HOVER_FLAG = 1;
        }
        else
        {
            HOVER_FLAG = 0;
        }
    }

    return;
}
//Author: Sam Buss December 2001
int Place :: LoadBackground(int time)
{
    const char* filename;

    // select time of day
    // delete current pointer if it has already been loaded
    if(time == NIGHTTIME)
    {
        filename = m_nightBGroundFile;
        if(m_imagePtrNight != NULL)
        {
            delete m_imagePtrNight;
        }
    }
    else // default to day
    {
        filename = m_dayBGroundFile;
        if(m_imagePtrDay != NULL)
        {
            delete m_imagePtrDay;
        }
    }

    // Open for reading binary data
    FILE* infile = fopen(filename, "rb");
    if(!infile)
    {
        fprintf(stderr, "%s: unable to open file: %s\n", __PRETTY_FUNCTION__, filename);
        exit(0);
    }

    // FIXME: I don't wanna check for BM... ughhhh
    int fileFormatOK = 0;
    int bChar = fgetc(infile);
    int mChar = fgetc(infile);

    int NumCols;
    int NumRows;

    // If starts with "BM" for "BitMap"
    if(bChar == 'B' && mChar == 'M')
    {			
        // Skip 4 fields we don't care about
        SkipChars(infile, 4 + 2 + 2 + 4 + 4);			
        
        NumCols = ReadLong(infile);
        NumRows = ReadLong(infile);

        // Skip one field
        SkipChars(infile, 2);					
        int bitsPerPixel = ReadShort(infile);
        // Skip 6 more fields
        SkipChars(infile, 4 + 4 + 4 + 4 + 4 + 4);		
        
        if(NumCols > 0 && NumCols <= 100000 &&
           NumRows > 0 && NumRows <= 100000 &&
           bitsPerPixel == 24 && !feof(infile))
        {
            fileFormatOK = 1;
        }
    }

    if(fileFormatOK == 0)
    {
        fclose(infile);
        fprintf(stderr, "%s - Not a valid 24-bit bitmap file\n",
                __PRETTY_FUNCTION__);
        exit(0);
    }

    if(time == NIGHTTIME)
    {
        // Allocate memory
        m_imagePtrNight = new unsigned char[NumRows * GetNumBytesPerRow(NumCols)];
        if(!m_imagePtrNight)
        {
            fclose (infile);
            fprintf(stderr, "%s: Unable to allocate memory for %s\n", __PRETTY_FUNCTION__, filename);
            exit(0);
        }

        unsigned char* cPtr = m_imagePtrNight;
        for(int i = 0; i < NumRows; i++)
        {
            for(int j = 0; j < NumCols; j++)
            {
                // blue, green, and red color value
                *(cPtr + 2) = fgetc(infile);
                *(cPtr + 1) = fgetc(infile);
                *cPtr = fgetc(infile);
                cPtr += 3;
            }

 		    // Num bytes already read
            int numBytes = GetNumBytesPerRow(NumCols);
            int k = 3 * NumCols;
            for(; k < numBytes; k++)
            {
			    // Read and ignore padding;
                fgetc(infile);
                *(cPtr++) = 0;
            }
        }

        if(feof(infile))
        {
            fclose (infile);
            fprintf(stderr, "%s: Premature end of file: %s.\n", __PRETTY_FUNCTION__, filename);
            exit(0);
        }

        // Close the file
        fclose(infile);
    }
    else // default to daytime
    {
        // Allocate memory
        m_imagePtrDay = new unsigned char[NumRows * GetNumBytesPerRow(NumCols)];
        if(!m_imagePtrDay)
        {
            fclose (infile);
            fprintf(stderr, "%s: Unable to allocate memory for %s\n", __PRETTY_FUNCTION__, filename);
            exit(0);
        }

        unsigned char* cPtr = m_imagePtrDay;
        for(int i = 0; i < NumRows; i++)
        {
            for(int j = 0; j < NumCols; j++)
            {
                // blue, green, and red color value
                *(cPtr + 2) = fgetc(infile);
                *(cPtr + 1) = fgetc(infile);
                *cPtr = fgetc(infile);
                cPtr += 3;
            }

 		    // Num bytes already read
            int numBytes = GetNumBytesPerRow(NumCols);
            int k = 3 * NumCols;
            for(; k < numBytes; k++)
            {
			    // Read and ignore padding;
                fgetc(infile);
                *(cPtr++) = 0;
            }
        }

        if(feof(infile))
        {
            fclose (infile);
            fprintf(stderr, "%s: Premature end of file: %s.\n", __PRETTY_FUNCTION__, filename);
            exit(0);
        }

        // Close the file
        fclose(infile);
    }

    return 1;
}

int Place :: DrawBackground(int time)
{
    glRasterPos2i(0, 0);
    if(time == NIGHTTIME)
    {
        glDrawPixels(SCREENWIDTH, SCREENHEIGHT, GL_RGB, GL_UNSIGNED_BYTE, m_imagePtrNight);
    }
    else // default to daytime
    {
        glDrawPixels(SCREENWIDTH, SCREENHEIGHT, GL_RGB, GL_UNSIGNED_BYTE, m_imagePtrDay);

    }

    return 1;
}
// Author: Dr. John Weiss, *THE* Weiss of the Weiss Distribution Method
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
