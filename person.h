#ifndef __PERSON_H__
#define __PERSON_H__

#include "globals.h"

class Person
{
public:
    Person();
    Person(char*, char*, TextColor, int, char*, char*);
    ~Person();

    // setters and getters
    int SetFirstName(char*);
    char* GetFirstName(void);
    int SetLastName(char*);
    char* GetLastName(void);
    int SetTextColor(TextColor);
    TextColor GetTextColor(void);
    int SetAge(int);
    int GetAge(void);
    int SetHello(char*);
    char* GetHello(void);
    int SetGoodbye(char*);
    char* GetGoodbye(void); 

    // functions
    int Speak(char*, int, int, int);

private:
    char* m_fName;
    char* m_lName;
    TextColor m_textColor; 
    int m_age;
    char* m_hello;
    char* m_goodbye;
    // should we have some flag
    // for if they are at the
    // current place
    // or a separate one for 
    // strictly phone call peeps?
};

#endif //__PERSON_H__
