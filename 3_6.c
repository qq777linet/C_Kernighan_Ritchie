//Kernighan&Ritchie 3.6

void itoa(int n, char s[], int min_width)
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
        min_width--;
        s[i++] = '0' + digit; 
    } while ((n /= 10) != 0); 
    if (sign < 0) 
    {
        s[i++] = '-'; 
        min_width--;
    }
    if(min_width>0)
    {
        while(min_width!=0)
        {
            s[i] = ' ';
            min_width--;
            i++;
        }
    }
    s[i] = '\0';              
    reverse(s);               
}
