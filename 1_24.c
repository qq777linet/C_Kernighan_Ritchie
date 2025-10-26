

#include<stdio.h>

int main(void)
{
    int round_br = 0;
    int square_br = 0;
    int curly_br = 0;
    int c;
    
    while((c = getchar()) != EOF)
    {
        if(c == '(')
        {
            round_br++;
        }
        else if(c == ')')
        {
            round_br--;   
        }
        else if(c == '[')
        {
            square_br++;   
        }
        else if(c == ']')
        {
            square_br--;   
        }
        else if(c == '{')
        {
            curly_br++;   
        }
        else if(c == '}')
        {
            curly_br--;   
        }
        else
        {
            ;
        }
    }
    
    if(round_br != 0)
    {
        printf("Error, number of round brackets is %d", round_br);
    }
    
    if(square_br != 0)
    {
        printf("Error, number of square brackets is %d", square_br);
    }
    
    if(curly_br != 0)
    {
        printf("Error, number of curly brackets is %d", curly_br);
    } 
    
    return 0;
}
