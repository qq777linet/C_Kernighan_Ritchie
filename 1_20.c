#include <stdio.h>
#define TAB 4

int main(void)
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c != '\t')
        {
            printf("%c", c);
        }
        else
        {
            for (int i = 0; i < TAB; i++)
            {
                putchar(' ');
            }
        }
    }
    printf("\n");
    return 0;
}
