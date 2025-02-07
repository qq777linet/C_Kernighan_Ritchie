int getword (char* word, int lim)
{
    int c; //temporary storage for char
    int flag = 0;
    int getch(void); 
    void ungetch(int);
    char* w = word; // pointer at string where word will be stored
    while (isspace(c = getch())) //skips spaces
    {
        ;
    }
    
    if (c != EOF)
    {
        *w = c; //now pointer points at first char from input
        w++; //now pointer points at next char from input
    }
    
    //work with comments // and /*...*/
    if(c == '/')
    {
        int next = getch();
        if(next == EOF)
        {
            *w = '\0';
            return c;
        }
        if(next == '/')
        {
            while((c = getch()) != '\n' && c != EOF)
            {
                ;
            }
            return getword(word, lim);
        }
        else if(next == '*')
        {
            while((c = getch()) != EOF)
            {
                
                if(c == '*' && flag == 0)
                {
                    flag = 1;
                }
                else if(c == '*' && flag == 1)
                {
                    ;
                }
                else if (c != '*' && flag == 1)
                {
                    flag = 0;
                }
                
                if(c == '/' && flag == 1)
                {
                    return getword(word, lim);
                }
            }
        }
        else
        {
            ungetch(next);
            *w++ = c; 
        }
    }
    
    //works with quotes
    if(c == '"')
    {
        while((c = getch()) != '"' && c != EOF)
        {
            ;
        }
        return getword(word, lim);
    }
    
    if (!isalpha(c)) 
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
    {
        if (!isalnum(*w = getch())) 
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
    
}
