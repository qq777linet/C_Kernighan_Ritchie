#include <stdio.h>
#include <stdbool.h>

#define ASCII 128

int main(void)
{
    int c;
    int ARR_OF_CHARS[ASCII];
    for(int i = 0; i < ASCII; i++)
    {
        ARR_OF_CHARS[i] = 0;
    }
    
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            ;
        }
        else
        {
            ARR_OF_CHARS[(int)c]++;
        }
    }
    
    for(int i = 0; i < ASCII; i++)
    {
        printf("ASCII %d :", i);
        for(int j = 0; j < ARR_OF_CHARS[i]; j++)
        {
            printf("_");
        }
        printf("\n");
    }
    
    return 0;
}
