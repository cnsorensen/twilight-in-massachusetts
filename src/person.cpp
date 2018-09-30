// person.cpp

#include "person.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constructors

Person :: Person()
: m_fName("")
, m_lName("")
, m_age(-1)
, m_hello("")
, m_goodbye("")
{
}

Person :: Person(const char* fName, const char* lName, int age, const char* hello, const char* bye)
: m_fName(fName)
, m_lName(lName)
, m_age(age)
, m_hello(hello)
, m_goodbye(bye)
{
}

// destructors

Person :: ~Person()
{
}

// setters and getters

int Person :: SetFirstName(const char* fName)
{
    m_fName = fName;

    return 1;
}

const char* Person :: GetFirstName(void)
{
    return m_fName;
}

int Person :: SetLastName(const char* lName)
{
    m_lName = lName;

    return 1;
}

const char* Person :: GetLastName(void)
{
    return m_lName;
}

//FIXME: do we need this?
int Person :: SetAge(int age)
{
    m_age = age;

    return 1;
}

int Person :: GetAge(void)
{
    return m_age;
}

int Person :: SetHello(const char* hello)
{
    // FIXME: make array of hellos and randomnly pick one
    m_hello = hello;
    return 1;
}

const char* Person :: GetHello(void)
{
    return m_hello;
}

int Person :: SetGoodbye(const char* bye)
{
    // FIXME: make array of byes and randomly pick one
    m_goodbye = bye;
    return 1;
}

const char* Person :: GetGoodbye(void)
{
    return m_goodbye;
}

// FIXME: need to implement
/*
int Person :: Speak(const char* dialog, int name_f, int type_f, int reply_num)
{
    int len;
    len = strlen(dialog);
    if(len < 0)
    {
        return -1;
    }

    fprintf(stdout, "\n");

    // decides wheter to put 'Name: ' in front of the dialog
    if(name_f == 1)
    {
        fprintf(stdout, "%s%s: ", m_textColor, m_fName);
    }
    else
    {
        fprintf(stdout, "%s", m_textColor);

    }

    // print dialog
    if(type_f == 0)
    {
        // If it's a reply, give reply number
        if(reply_num != 0)
        {
            fprintf(stdout, "%d) ", reply_num);
        }

        fprintf(stdout, "%s\n", dialog);
        fflush(stdout);
    }
    else //FIXME: I'm not using this for development
    {
        // prints char by char, give it a typing look
        for(int i = 0; i < len; i++)
        {
            fprintf(stdout, "%c", dialog[i]);
            fflush(stdout);
            usleep(20000);
        }
        fprintf(stdout, "\n");
    }

    return 1;
}
*/
