#ifndef __PERSON_H__
#define __PERSON_H__

#include "globals.h"

class Person
{
public:
    Person();
    Person(const char*, const char*, int, const char*, const char*);
    ~Person();

    // setters and getters
    int SetFirstName(const char*);
    const char* GetFirstName(void);
    int SetLastName(const char*);
    const char* GetLastName(void);
    //int SetTextColor(TextColor);
    //TextColor GetTextColor(void);
    int SetAge(int);
    int GetAge(void);
    int SetHello(const char*);
    const char* GetHello(void);
    int SetGoodbye(const char*);
    const char* GetGoodbye(void);

    // functions
    //int Speak(const char*, int, int, int);

private:
    const char* m_fName;
    const char* m_lName;
    //TextColor m_textColor;
    int m_age;
    const char* m_hello;
    const char* m_goodbye;
    // should we have some flag
    // for if they are at the
    // current place
    // or a separate one for
    // strictly phone call peeps?
};

#endif //__PERSON_H__
