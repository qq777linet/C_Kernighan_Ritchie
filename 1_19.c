#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[]);
void copy(char to[], char from[]);
void reverse(char string[], int len);

int main(void)
{
    char string[MAXLINE];
    int len;

    printf("Enter string: ");
    len = get_line(string);
    reverse(string, len);
    for(int i = 0; i < len; i++)
    {
        printf("%c", string[i]);
    }
    return 0;
}

int get_line(char s[])
{
    int i;
    char c;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void reverse(char string[], int len)
{
    char temp[len + 1];

    for (int i = 0; i < len; i++)
    {
        temp[i] = string[len - i - 1];
    }

    temp[len] = '\0';
    copy(string, temp);
}


void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}
