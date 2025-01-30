#include <ctype.h>
int getch (void);
void ungetch (int);
/* getint: читает следующее целое из ввода в *pn */
int getint(int* pn)
{
    int c;
    int sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c ! = '+' && c != '-' ) 
    {
        ungetch (c); 
        return 0;
    }
    sign = (c == '-' ) ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if(isdigit(c))
        {
            ;
        }
        else
        {
            ungetch(c);
            ungetch(sign);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0' ) ;
        *pn *= sign;
    }
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
