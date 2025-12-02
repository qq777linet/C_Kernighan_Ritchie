//Kernighan&Ritchie 3.2

void escape(char s[], char t[]) //copies text from t to s, \n \t make visible
{
    for(int i = 0, j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
            case '\n' :
            {
                s[j] = '\\';
                j++;
                s[j] = 'n';
                j++;
                break;
            }
            case '\t' :
            {
                s[j] = '\\';
                j++;
                s[j] = 't';
                j++;
                break;
            }
            default:
            {
                s[j] = t[i];
                j++;
                break;
            }
        }
    }
    s[j] = '\0';
} 
