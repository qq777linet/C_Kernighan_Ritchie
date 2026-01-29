
// Kernighan&Ritchie 4.12 - itoa with recursion 

int GL_C = 0; //global counter


void itoa (int n, char s[])
{
    int sign;
    if ((sign = n) < 0) 
    {
        n = -n; //makes n positive
    }
    if((n/10) != 0)
    {
        s[GL_C] = (n%10) + '0';
        GL_C++;
        itoa(n/10, s);
    }
    else
    {
        s[GL_C] = (n%10) + '0';
        if(sign<0)
        {
            s[GL_C + 1] = '-';
            s[GL_C + 2] = '\0';
        }
        else
        {
            s[GL_C + 1] = '\0';
        }
        reverse(s);
    }
}

