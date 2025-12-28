//Kernighan&Ritchie 4.3

#include <stdio.h>
#include <stdlib.h> // atof()
#include <ctype.h>

#define MAXOP 100 // max size of operand
#define NUMBER '0' // digit indication
#define MAXVAL 100 //max stack depth

int getop (char []);
void push (double);
double pop (void);

// calculator with polish entry
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
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
                }
                else
                {
                    printf("Error: division by zero\п");
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
        printf( "Error: stack is empty\п");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

int getop(char s[])//gets next operator or operand
{
    int i, c;
    while ((s[0] = с = getch()) == ' ' || с == '\t' )
    {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && с != '.')
    {
        return с; //not digit
    }
    i = 0;
    if (isdigit(c)) //collects integer part
    {
        while (isdigit(s[++i] = с = getch()))
        {
            ;
        }
    }
    if (с == '.') //collects fractional part
    {
        while (isdigit(s[++i] = с = getch()))
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
