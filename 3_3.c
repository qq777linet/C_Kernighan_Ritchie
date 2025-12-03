//Kernighan&Ritchie 3.3 

void expand(char s1[], char s2[])  
{
    int i = 0;
    int j = 0;
    
    while(s1[i] != '\0')
    {
        if(s1[i] != '-')
        {
            s2[j] = s1[i];
            i++;
            j++;
        }
        else if((s1[i] == '-') && (i != 0))
        {
            if((s1[i-1]<s1[i+1])&&(s1[i-1] >= 65)&&(s1[i+1] <= 90)) // A-Z
            {
               for(int k = s1[i-1] + 1; k <= s1[i+1]; k++)
               {
                   s2[j] = k;
                   j++;
               }
               i++;
               i++;
            }
            else if((s1[i-1]<s1[i+1])&&(s1[i-1] >= 97)&&(s1[i+1] <= 122)) // a-z
            {
               for(int k = s1[i-1] + 1; k <= s1[i+1]; k++)
               {
                   s2[j] = k;
                   j++;
               }
               i++;
               i++;
            }
            else if((s1[i-1]<s1[i+1])&&(s1[i-1] >= 48)&&(s1[i+1] <= 57)) // 0-9
            {
                for(int k = s1[i-1] + 1; k <= s1[i+1]; k++)
               {
                   s2[j] = k;
                   j++;
               }
               i++;
               i++;
            }
            else
            {
                s2[j] = s1[i];
                i++;
                j++;
            }
        }
    }
    
    s2[j] = '\0';
}
