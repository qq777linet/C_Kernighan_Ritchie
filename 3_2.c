
void escape(char s[], char t[])
{

    char c;
    int i = 0;
    int j = 0;
    while((c = s[i]) != '\0')
    {
        switch (c)
        {
            case '\n':
                t[j] = '\\';
                t[j+1] = 'n';
                i++;
                j +=2;
                break;
            
            case '\t':
                t[j] = '\\';
                t[j+1] = 't';
                i++;
                j +=2;
                break;
            
            default:
                t[j] = s[i];
                i ++;
                j ++;
                break;
        }
    }
}
