void itoa(int n, char s[])
{
    int i = 0;
    int sign = n;

    do 
    {
        int digit = n % 10;   

        if (digit < 0) 
        {
            digit = -digit;   
        }

        s[i++] = '0' + digit; 
    } while ((n /= 10) != 0); 
    if (sign < 0) 
    {
        s[i++] = '-';         
    }

    s[i] = '\0';              
    reverse(s);               
}
