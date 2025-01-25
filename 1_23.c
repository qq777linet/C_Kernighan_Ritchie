#include <stdio.h>

int main(void)
{
    char c;
    int alarm = 0;
    while((c = getchar()) != EOF)
    {
        if(c != '/')
        {
            alarm = 0;
            printf("%c",c);
        }
        else if(c == '/' && alarm == 0)
        {
            if((c = getchar()) == '/')
            {
               while((c == getchar()) != '\n')
               {
               }
            }
        }

    }
    printf("\n");
}
