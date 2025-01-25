#include <stdio.h>

int main(void)
{
    char c;
    int counter = 0;
    int max = 20;
    while((c = getchar()) != EOF)
    {
        if((c != '\n') && (counter<max))
        {
            counter++;
            printf("%c",c);
        }
        else if((c == '\n')&&(counter<max))
        {
            counter = 0;
            printf("\n");
        }
        else if((c != '\n')&&(counter==max))
        {
            counter = 0;
            printf("\n");
        }і

    }
    printf("\n");
}
