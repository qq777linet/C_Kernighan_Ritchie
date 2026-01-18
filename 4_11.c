//Kernighan&Ritchie 4.11 - uses static variable, does not use ungetch()

int getop(char s[])//gets next operator or operand, returns type, stores in char s[]
{
    #define GET (flag == 0)?(getch()):(flag = 0, temp)
    #define UNGET(x) (flag = 1, temp = x)
    static int temp = 0;
    static int flag = 0;
    int i, c; //i - counter; c - buffer
    int next = 0; //for '-' handling in getop
    while ((s[0] = (c = GET)) == ' ' || c == '\t' ) //skip spaces and tabulation
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
            c = GET;
        }
        s[i] = '\0';
        if (c != EOF) 
        {    
            UNGET(c);
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
        next = GET;
        if(!isdigit(next) && next != '.')
        {
            UNGET(next);
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
        while (isdigit(s[++i] = (c = GET)))
        {
            ;
        }
    }
    if (c == '.') //collects fractional part
    {
        while (isdigit(s[++i] = c = GET))
        {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        UNGET(c);
    }
    return NUMBER;
}
