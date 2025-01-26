#include <stdio.h>
#include <string.h>


int any(char s1[], char s2[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int alarm = 0;
    
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            if(s1[i] == s2[j])
            {
                alarm = 1;
            }
        }
        if (alarm == 1)
        {
            return i;
            break;
        }
        if( i == (len1-1) && alarm == 0)
        {
            return -1;
        }
    }
}

