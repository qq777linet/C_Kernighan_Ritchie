//Kernighan&Ritchie 4.10 (getop works with getline() and does not use getch())

#include <ctype.h>

#define MAXOP 100
#define MAXLINE 1000
#define VAR 'v'
#define NAME 'n'
#define NUMBER '0'

int getline(char s[], int lim) 
{
    int c, i;

    for (i = 0;
         i < lim - 1 && (c = getchar()) != EOF && c != '\n';
         i++)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

char buffer[MAXLINE]; //buffer
int length = getline(buffer, MAXLINE); 
int pos = 0; 

int getop(char s[], char buffer[])//gets next operator or operand, returns type, stores in char s[]
{
    int i = 0;
    while(buffer[pos] == ' ')
    {
        pos ++; //skip spaces
    }
    if(buffer[pos] == '\n') 
    {
        pos++;
        return '\n';
    }
    
    if(isalpha(buffer[pos]))
    {
        if(buffer[pos+1] == ' ' || ) //handling variables
        {
            s[0] = tolower(buffer[pos]);
            s[1] = '\0';
            return VAR;
        }
        else //handling strings
        {
            while(buffer[pos] != ' ' && buffer[pos] != '\n')
            {
                s[i] = buffer[pos];
                i++;
                pos++;
            }
            s[i] = '\0';
            return NAME;
        }
    }
    if(buffer[pos] == '-') //handling - and -digits
    {
        if(buffer[pos+1] == ' ')
        {
            s[0] = '-';
            s[1] = '\0';
            pos+=2;
            return '-';
        }
        else
        {
            while(buffer[pos] != ' ' && buffer[pos] != '\n')
            {
                s[i] = buffer[pos];
                i++;
                pos++;
            }
            s[i] = '\0';
            return NUMBER;
        }
    }
    if(isdigit(buffer[pos]))
    {
        while(buffer[pos] != ' ' && buffer[pos] != '\n')
            {
                s[i] = buffer[pos];
                i++;
                pos++;
            }
            s[i] = '\0';
            return NUMBER;
    }
    return buffer[pos++];
}
/* pseudocode
- return NUMBER
- return VAR
- return NAME
- return operator
*/
