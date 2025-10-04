#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            putchar('\n');
        }
        else
        {
            putchar(c);
        }
    }
    
    return 0;
}
