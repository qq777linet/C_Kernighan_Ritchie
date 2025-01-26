#include <stdio.h>
#include <string.h>


void squeeze(char s1[], char s2[])
{
    int len = strlen[s1];
    int len2 = strlen[s2];
    int alarm = 0;
    char s3[len];
    int k = 0;
    for(int i = 0; i < (len); i++)
    {
        for(int j = 0; j < (len2); j++)
        {
            if(s1[i] == s2[j])
            {
              alarm = 1;  
            }
        }
        if(alarm == 0)
        {
            s3[k] = s1[i];
            k++;
        }
        alarm = 0;
    }
    for(int l = 0; l<len; l++)
    {
        s1[l] = s3[l];
    }
}

