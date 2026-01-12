//Kernighan&Ritchie 4.7

//ungets (returns string to incoming flow)

#include <stdio.h>

#define MAXLINE 1000

void ungets(char s[MAXLINE])
{
    int i = 0; //counter
    char buff[MAXLINE];
    
    while(s[i] != '\0')
    {
        buff[i] = s[i];
        i++;
    }
    buff[i] = s[i];
    i--;
    while (i >= 0)
    {
        ungetch(buff[i]);
        i--;
    } 
}
