//Kernighan&Ritchie 5.1

#include <ctype.h>
#include <stdio.h>

int getch (void);

void ungetch (int);

/* getint: reads next int from input to *pn */
int getint(int* pn)
{
    int c, sign;
    while (isspace(c = getch()))
    {
        ; /* skips spaces */
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' ) 
    {
        ungetch (c); /* no digit */
        return 0;
    }
    sign = (c == '-' ) ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if(!isdigit(c))
        {
            ungetch(c);
            if(sign == 1)
            {
                ungetch('+');
            }
            else
            {
                ungetch('-');
            }
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0' ) ;
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
