#include <stdio.h>

#define MAXLINE 1000

int main(void)
{
    char inline[MAXLINE];
    char outline[MAXLINE];
    int flag = 0;
    int length;
    
    while((length = get_line(inline, MAXLINE)) != 0)
    {
        if(length == 1)
        {
            ;
        }
        else
        {
            flag = 0;
            for(int i = 0, j = 0; i < length; i++)
            {
                if((inline[i] == '\t' || inline[i] == ' ') && flag == 0)
                {
                    flag = 1;
                    outline[j] = inline[i];
                    j++;
                }
                else if((inline[i] == '\t' || inline[i] == ' ') && flag == 1)
                {
                    ;
                }
                else
                {
                    flag = 0;
                    outline[j] = inline[i];
                    j++;
                }
            }
            outline[j] = '\0';
        }
            printf("%s", outline);
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



