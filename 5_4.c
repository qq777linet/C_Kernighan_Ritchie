
// Kernighan&Ritchie 5.4 

#include<stdio.h>

//returns 1 if string t is located at the end of string s, and 0 if not 
int strend(char* s, char* t)
{
    int T_LENGTH = 0;
    while(*t != '\0')
    {
        t++;
        T_LENGTH++;
    }
    int S_LENGTH = 0;
    while(*s != '\0')
    {
        s++;
        S_LENGTH++;
    }
    s--;
    t--;
    while(T_LENGTH != 0)
    {
        if(*t != *s)
        {
            return 0;
        }
        t--;
        s--;
        T_LENGTH--;
    }
    return 1;
}
