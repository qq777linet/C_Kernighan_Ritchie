#include<stdio.h>

int main(void)
{
    int flag = 0;
    int flag_2 = 0;
    int c;
    
    while((c = getchar()) != EOF)
    {
        if(c == '/' && flag == 0)
        {
            flag = 1;
        }
        else if(c == '/' && flag == 1)
        {
            while((c = getchar()) != '\n')
            {
                ;
            }
            printf("\n");
            flag = 0;
        }
        else if(c != '/' && flag == 0)
        {
            printf("%c", c);
        }
        else if(c != '/' && c != '*' && flag == 1)
        {
            printf("/");
            printf("%c", c);
            flag = 0;
        }
        else if(c == '*' && flag == 1)
        {
            while((c = getchar()) != EOF) 
            {
                if(c == '*')
                {
                    flag_2 = 1;
                }
                
                if(c != '*' && c != '/')
                {
                    flag_2 = 0;
                }
                
                if(c == '/' && flag_2 == 1)
                {
                    printf("\n");
                    break;
                }
                
            }
            flag = 0;
        }

    }
    return 0;
}
