#include <stdio.h>

#define TAB 8

int main(void)
{
    int c;
    int counter = 0;
    
    while((c = getchar()) != EOF)
    {
        if(c != '\t')
        {
            printf("%c", c);
            counter ++;
        }
        else
        {
            do
            {
            printf(" ");
            counter ++;
            }
            while
            (counter%TAB != 0);
        }
    }
    
    return 0;
}
