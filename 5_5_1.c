
// Kernighan&Ritchie 5.5.1

#include<stdio.h>

//copies n symbols from t to s
void strncpy(char* s, char* t, int n)
{
    for(int i = 0; i < n && *t != '\0'; i++)
    {
        *s = *t;
        s++;
        t++;
    }
}
