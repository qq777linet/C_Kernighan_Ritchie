

#include<stdio.h>

int main(void)
{
    int c, test;
    while((c = getchar()) != EOF)
    {
        if (c != ' ')
        {
            putchar(c);
            test = 0;
        }
        else 
        {
            if ( test == 0)
            {
                putchar(c);
                test = 1;
            } 
            else if (test == 1)
            {
                test = 1;
            }
        }
    }
    return 0;
}
