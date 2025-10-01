

#include<stdio.h>

int main()
{
    int c, spaces, new_lines, tab;
    spaces = 0;
    new_lines = 0;
    tab = 0;
    while((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            new_lines++;
        }
        if (c == '\t')
        {
            tab++;
        }
        if (c == ' ')
        {
            spaces++;
        }
    }
    printf("%d, %d, %d\n",new_lines, tab, spaces);
    return 0;
}
