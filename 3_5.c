//Kernighan&Ritchie 3.5

int itob(int n, char s[], int b)
{
    if((b != 2)&&(b != 10)&&(b != 16))
    {
        return 1;
    }
    
    int i = 0;
    
    if(b == 10) // decimal format
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
    else if (b == 2) // binary format
    {
        int sign = n;
        unsigned int x = (sign < 0) ? (unsigned int)(-(long long)n) : (unsigned int)n;
        do
        {
            s[i] = '0' + x%2;
            x /= 2;
            i++;
        } while (x != 0);
        
        s[i] = '\0';
        reverse(s);
        
    }
        else if (b == 16) // hex format
    {
        int sign = n;
        unsigned int x = (sign < 0) ? (unsigned int)(-(long long)n) : (unsigned int)n;
        
        do
        {
            int z = x%16;
            s[i] = (z<10)?('0' + z):('0' + z + 7);
            x /= 16;
            i++;
        } while (x != 0);
        s[i] = '\0';
        reverse(s);
        
    }
    
    return 0;
}




