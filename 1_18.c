#include <stdio.h>

int main(void)
{
    char c;
    int alarm = 0;
    while((c = getchar()) != EOF)
    {
        if(c != ' ')
        {
            printf("%c",c);
            alarm = 0;
        }
        else if(c == ' ' && alarm == 0)
        {
            printf("%c",c);
            alarm = 1;
        }
        else if(c == ' ' && alarm == 1)
        {
            printf("");
            alarm = 1;
        }
    }
    printf('\n');
}
