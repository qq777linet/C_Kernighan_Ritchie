
// Kernighan&Ritchie 5.5.2

#include<stdio.h>

// adds n symbols of t to s
void strncat(char* s, char* t, int n)
{
    while(*s != '\0')
    {
        s++;
    }
    for(int i = 0; (i < n)&&(*(t+i) != '\0'); i++)
    {
        *s = *(t+i);
        s++;
    }
    *s = '\0';
}
