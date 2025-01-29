void itoa(int n, char s[]) 
{
    int i = 0;
    int sign = 0;
    unsigned int num = 0;

    if (n == INT_MIN) 
    {  
        num = (unsigned int)INT_MIN;
    } 
    else 
    {
        sign = n;
        num = (n < 0) ? -n : n; 
    }

    do 
    {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (n < 0) 
    {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}
