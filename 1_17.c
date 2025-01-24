#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[]);

int main(void)
{
    char string[MAXLINE];
    int len;  
    int max = 80;

    while ((len = get_line(string)) > 0) 
    {
        if (len > max) 
        {
            printf("String is too big:\n", max);
            for (int i = 0; i < len; i++) 
            {
                printf("%c", string[i]);
            }
            printf("\n"); 
        }
    }

    return 0;
}

int get_line(char s[])
{
    int c, i;
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
