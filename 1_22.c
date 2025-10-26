#include <stdio.h>

#define N_POS 40

int get_line(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    
    s[i] = '\0';
    
    if (c == EOF)
        return 1;
    if (c == '\n')
        return 2;
    return 0;
}

int main(void)
{
    int test;
    int counter;
    char str[N_POS + 1];
    char rest_buf[N_POS + 1] = "";  /
    
    while ((test = get_line(str, N_POS)) != 1)
    {

        if (rest_buf[0] != '\0')
        {
            int i = 0;
            while (rest_buf[i] != '\0')
            {
                putchar(rest_buf[i]);
                i++;
            }
            rest_buf[0] = '\0'; 
        }

        if (test == 2)
        {
            printf("%s\n", str);
        }
        else if (test == 0)
        {

            for (counter = N_POS - 1; counter > 0 && str[counter] != ' ' && str[counter] != '\t'; counter--)
                ;

            if (counter == 0)
            {
                printf("%s\n", str);
            }
            else
            {
                int j = 0;
                for (int i = counter + 1; str[i] != '\0'; i++)
                    rest_buf[j++] = str[i];
                rest_buf[j] = '\0';
                str[counter] = '\0';
                printf("%s\n", str);
            }
        }
    }
    if (rest_buf[0] != '\0')
        printf("%s\n", rest_buf);

    return 0;
}
