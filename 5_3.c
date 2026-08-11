
// Kernighan&Ritchie 5.3 

#include<stdio.h>

//copies string t to end of string s
void strcat(char* s, char* t)
{
    while(*s != '\0')
    {
        s++;
    }
    while(*t != '\0')
    {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';
}
