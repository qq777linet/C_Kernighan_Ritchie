#include <stdio.h>

#define TAB_STOP 4 

void entab(const char *input);

int main(void) 
{
    char c;
    char buffer[1024];
    int index = 0;

    while ((c = getchar()) != EOF && index < 1023) 
    {
        buffer[index++] = c;
    }
    buffer[index] = '\0';

   
    entab(buffer);

    return 0;
}


void entab(const char *input) {
    int column = 0; 
    int space_count = 0; 

    for (const char *p = input; *p != '\0'; p++) {
        if (*p == ' ') {
          
            space_count++;
        
            if ((column + space_count) % TAB_STOP == 0) {
                putchar('\t'); 
                space_count = 0; 
            }
        } else {
 
            for (int i = 0; i < space_count; i++) {
                putchar(' ');
            }
            space_count = 0;
            putchar(*p);
            column = (*p == '\n') ? 0 : column + 1;
        }

        if (*p != ' ') {
            column++;
        }
    }

    for (int i = 0; i < space_count; i++) {
        putchar(' ');
    }
}
