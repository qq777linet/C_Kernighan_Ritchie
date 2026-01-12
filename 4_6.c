//Kernighan&Ritchie 4.5

#include <stdio.h>
#include <stdlib.h> // atof()
#include <ctype.h>
#include <math.h>  // fmod
#include <string.h>
#include <stdbool.h>


#define MAXOP 100 // max size of operand
#define NUMBER '0' // digit indication
#define MAXVAL 100 //max stack depth
#define NAME 'n'
#define VAR 'v' // for variable

int getop (char []);
void push (double);
double pop (void);
int getch(void);
void ungetch(int);
void print_stack_top(void);
void duplicate(void);
void change(void);
void clean(void);

// calculator with polish entry
int main(void)
{
    int type;
    double op2;
    char s[MAXOP]; //operand
    double VAR_VAL[26] = {0.0}; // array of variable's values
    bool VAR_ST[26] = {false}; // array of variable's statuses
    int LAST_VAR = 0; // for variables handling
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
            case '?':
                print_stack_top();
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
            case '=' :
                pop();
                VAR_VAL[LAST_VAR] = pop();
                VAR_ST[LAST_VAR] = true;
                break;
            case VAR:
                if(VAR_ST[atoi(s[0] - 'A')] == true)
                {
                    push(VAR_VAL[atoi(s[0] - 'A')]);
                }
                else
                {
                    push(0.0);
                    LAST_VAR = atoi(s[0] - 'A');
                }
                break;
            case NAME:
                if (strcmp(s, "sin") == 0) 
                {
                    push(sin(pop()));
                }
                else if (strcmp(s, "exp") == 0) 
                {
                    push(exp(pop()));
                }
                else if (strcmp(s, "pow") == 0) 
                { 
                    op2 = pop(); 
                    push(pow(pop(), op2)); 
                }
                else if (strcmp(s, "dup") == 0) 
                { 
                    duplicate();
                }
                else if (strcmp(s, "swap") == 0) 
                { 
                    change();
                }
                else if (strcmp(s, "clear") == 0) 
                { 
                    clean();
                }
                else
                {
                    printf("Error: unknown function %s\n", s);
                }
                break;
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

void print_stack_top(void)
{
    if (sp > 0)
    {
        printf("\t%.8g\n", val[sp - 1]);
    }
    else
    {
            printf("Error: stack is empty\n");
    }
}

void duplicate(void)
{
    if (sp > 0)
    {
        double temp = pop();
        push(temp);
        push(temp);
    }
    else
    {
        printf("Error: stack is empty\n");
    }
}

void change(void)
{
    if (sp > 1)
    {
        double temp = pop();
        double temp2 = pop();
        push(temp);
        push(temp2);
    }
    else
    {
        printf("Error: stack is too small\n");
    }   
}

void clean(void)
{
    while(sp != 0)
    {
        pop();
    }
}

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

/* pseudocode

- 

*/
