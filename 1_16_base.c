#include <stdio.h>
#define MAXLINE 1000 // max line size

int get_line(char linef[], int lim);
void copy(char to[], char from[]);


int main(void)
{
    int len; // current length 
    int max; // max length 
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // longest line
    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > max) 
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) // was there at least one line?
    {
        printf("%s", longest);
    }
    return 0;
}
// getline: reads line in s, returns length
int get_line(char s[], int lim)
{
    int c, length;
    for (length = 0; length < lim-1 && (c = getchar()) != EOF && c != '\n'; ++length)
    {
        s[length] = c;
    }
    if (c == '\n'); 
    {
        s[length] = c;
        ++length;
    }
    s[length] = '\0';
    return length;
}
// copies from "from" to "to"
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}
