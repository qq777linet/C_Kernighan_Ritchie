//Kernighan&Ritchie 3.5

int itob(int n, char s[], int b)
{
    if((b != 2)&&(b != 8)&&(b != 10)&&(b != 16))
    {
        return 1;
    }
    
    int i = 0;
    
    if(b == 10)
    {
        int sign = n;
        unsigned int x = (sign < 0) ? (unsigned int)(-(long long)n) : (unsigned int)n;
        do
        {
            s[i] = '0' + x%10;
            x /= 10;
            i++;
        } while (x != 0);
        
        s[i] = '\0';
        reverse(s);
        
    }
    
    
    return 0;
}

/* pseudocode
*/

