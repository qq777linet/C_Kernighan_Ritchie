//Kernighan&Ritchie 4.3

#include <stdio.h>
#include <stdlib.h> // atof()

#define MAXOP 100 // max size of operand
#define NUMBER '0' // digit indication

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
