#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int c;
    int WORD_LENGTH[45];
    for(int i = 0; i<45; i++)
    {
        WORD_LENGTH[i] = 0;
    }
    bool INSIDE = false;
    int length = 0;
    
    while((c = getchar()) != EOF)
    {
        if(INSIDE == true)
        {
            if(c == ' ' || c == '\n' || c == '\t')
            {
                INSIDE = false;
                WORD_LENGTH[length]++;
                length = 0;
            }
            else
            {
                length++;
            }
        }
        else
        {
            if(c == ' ' || c == '\n' || c == '\t')
            {
                INSIDE = false;
            }
            else
            {
                INSIDE = true;
                length++;
            }            
        }
    }
    if (INSIDE && length > 0)
    {
        WORD_LENGTH[length]++;
    }
    for(int i = 0; i < 45; i++)
    {
        printf("%d: ", i);
        for(int j = 0; j < WORD_LENGTH[i]; j++)
        {
            printf("_");
        }
        printf("\n");
    }
    return 0;
}
