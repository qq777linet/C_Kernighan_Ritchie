#include <stdio.h>
#include <ctype.h>

int htol(const char* s) 
{
    int result = 0;  
    int i = 0;


    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) 
    {
        i = 2;
    }


    for (; s[i] != '\0'; i++) 
    {
        char c = s[i];
        int value;

        if (isdigit(c)) 
        {
            value = c - '0';  
        } 
        else if (c >= 'a' && c <= 'f') 
        {
            value = c - 'a' + 10; 
        } 
        else if (c >= 'A' && c <= 'F') 
        {
            value = c - 'A' + 10;  
        } 
        else 
        {
            break;
        }
        result = result * 16 + value;
    }

    return result;
}

