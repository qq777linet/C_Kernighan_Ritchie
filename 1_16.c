#include <stdio.h>
#define MAXLINE 1000 // max line size

int get_line(char linef[], int lim);
void copy(char to[], char from[]);


int main(void)
{
    int len; 
    int curr_len = 0;
    int max; // max length 
    char line[MAXLINE]; 
    char curr_line[MAXLINE];
    char longest[MAXLINE]; // longest line
    max = 0;
    int test = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
       if(len < MAXLINE - 1) 
       {
            if(test == 0) //case1
            {
                if(len > max)
                {
                    max = len;
                    copy(longest, line);
                }
                else
                {
                    ;
                }
            }
            else if(test == 1) //case 2
            {
                test = 0;
                curr_len += len;
                if(curr_len > max)
                {
                    max = curr_len;
                    copy(longest, curr_line);
                    curr_len = 0;
                }
                else
                {
                    curr_len = 0;
                }
            }
       }
        else // case 3
        {
            if (test == 0) 
            {         
                copy(curr_line, line);
                test = 1;
                curr_len = len;
            } 
            else 
            {                 
                curr_len += len;
            }
        }

    }
    // поч
    if (test == 1 && curr_len > max)
    {
        max = curr_len;
        copy(longest, curr_line);
    }
    //кінець
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
    if (c == '\n') 
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
