// Kernighan&Ritchie 2.5
int any(char s1[], char s2[])
{
    int i = 0;
    
    while(s1[i] != '\0')
    {
        for(int j = 0; s2[j] != '\0'; j++)
        {
            if(s1[i] == s2[j])
            {
                return i;
            }
        }
        i++;
    }
    
    i = (-1);
    return i;
}
