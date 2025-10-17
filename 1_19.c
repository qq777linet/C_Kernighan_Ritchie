#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[])
{
    int size = 0;
    while(s[size] != '\0')
    {
        size ++;
    }
    char s2[size + 1];
    for(int i = 0; i < size; i++)
    {
        s2[i] = s[size - 1 -i];
    }
    s2[size] = '\0';
    copy(s, s2);
}

int main(void)
{
    int length;
    char s[MAXLINE];
    
    while((length = get_line(s, MAXLINE)) != 0)
    {
        reverse(s);
        printf("%s", s);
    }
}

int get_line(char s[], int lim)
{
    int c, length;
    for (length = 0; length < lim-1 && (c = getchar()) != EOF && c != '\n'; ++length)
    {
        s[length] = c;
    }
    if (c == '\n') 
    {
        s[length] = c;
        ++length;
    }
    s[length] = '\0';
    return length;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}


