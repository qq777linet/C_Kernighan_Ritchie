//Kernighan&Ritchie 4.3

#include <stdio.h>
#include <stdlib.h> // atof()
#include <ctype.h>
#include <math.h>  // fmod


#define MAXOP 100 // max size of operand
#define NUMBER '0' // digit indication
#define MAXVAL 100 //max stack depth

int getop (char []);
void push (double);
double pop (void);
int getch(void);
void ungetch(int);

// calculator with polish entry
int main(void)
{
    int type;
    double op2;
    char s[MAXOP]; //operand
    while ((type = getop (s)) != EOF) 
    {
        switch (type) 
        {
            case NUMBER:
                push (atof (s));
                break;
            case '+':
                push (pop() + pop());
                break;
            case '*':
                push (pop() * pop());
                break;
            case '-':
                op2 = pop();
                push (pop() - op2);
                break;
            case '/' :
                op2 = pop();
                if (op2 != 0.0)
                {
                    push (pop() / op2);
                    break;
                }
                else
                {
                    printf("Error: division by zero\n");
                    break;
                }
            case '%' :
                op2 = pop();
                if (op2 != 0.0)
                {
                    push (fmod(pop(), op2));
                    break;
                }
                else
                {
                    printf("Error: division by zero\n");
                    break;
                }
            case '\n' :
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown operation %s\n", s);
                break;
            }
    }
 return 0;
}

int sp = 0; //next position in stack
double val[ MAXVAL ]; //stack

void push(double f) //puts value in stack
{
    if (sp < MAXVAL)
    {    
        val[sp++] = f;
    }
    else
    {   
        printf( "Error:stack overflow, %g does not fits\n", f);
    }
}

double pop(void) //returns top of stack
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else 
    {
        printf( "Error: stack is empty\n");
        return 0.0;
    }
}

int getop(char s[])//gets next operator or operand
{
    int i, c; //i - counter; c - buffer
    int next = 0; //for '-' handling in getop
    while ((s[0] = c = getch()) == ' ' || c == '\t' ) //skip spaces and tabulation
    {
        ;
    }
    s[1] = '\0'; 
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
            i++;
        }
    }
    if (isdigit(c)) //collects integer part
    {
        while (isdigit(s[++i] = c = getch()))
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

/* pseudocode

- 

*/
