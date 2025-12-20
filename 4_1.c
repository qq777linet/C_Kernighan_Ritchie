//Kernighan&Ritchie 4.1

int strindex (char s[], char t[])
{
    int i, j, k;
    int temp = (-1);
    for (i = 0; s[i] != '\0'; i++) 
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        {
            ;
        }
        if (k > 0 && t[k] == '\0')
        {
            temp = i;
        }
    }
    if(temp != (-1))
    {
        return temp;
    }
    return -1;
}
