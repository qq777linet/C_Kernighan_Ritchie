//Kernighan&Ritchie 4.11

int getop(char s[])//gets next operator or operand, returns type, stores in char s[]
{
    int i, c; //i - counter; c - buffer
    int next = 0; //for '-' handling in getop
    while ((s[0] = c = getch()) == ' ' || c == '\t' ) //skip spaces and tabulation
    {
        ;
    }
    s[1] = '\0'; 
    if (isalpha((unsigned char)c)) 
    {
        i = 0;
        while (isalpha((unsigned char)c)) 
        {
            s[i++] = c;
            c = getch();
        }
        s[i] = '\0';
        if (c != EOF) 
        {    
            ungetch(c);
        }
        if(i == 1)
        {
            return VAR;
        }
        return NAME;
    }
    if (!isdigit(c) && c != '.' && c!= '-')
    {
        return c; //not digit
    }
    i = 0;
    if(c == '-')
    {
        next = getch();
        if(!isdigit(next) && next != '.')
        {
            ungetch(next);
            return c;
        }
        else
        {
            s[i] = c;
            i++;
            s[i] = next;
            c = next;
        }
    }
    if (isdigit(c)) //collects integer part
    {
        while (isdigit(s[++i] = (c = getch())))
        {
            ;
        }
    }
    if (c == '.') //collects fractional part
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}
