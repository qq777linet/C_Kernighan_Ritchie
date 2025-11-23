void squeeze(char s1[], char s2[])
{
    char s3[MAXLINE];
    
    int k = 0;
    
    for(int i = 0; i < MAXLINE; i++)
    {
        if(s1[i] == '\0')
        {
            break;
        }
        for(int j= 0; j < MAXLINE; j++)
        {
            if(s2[j] == '\0')
            {
                s3[k] = s1[i];
                k++;
                break;
            }
            if(s2[j] == s1[i])
            {
                break;
            }
        }
    }
    s3[k] = '\0';
    copy(s1, s3);
}
