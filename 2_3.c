//Kernighan&Ritchie 2.3
int htod(char a)
{
    int b;
    if(a == '1')
    {
        b = 1;
    }
    else if(a == '2')
    {
        b = 2;
    }
    else if(a == '3')
    {
        b = 3;
    }
    else if(a == '4')
    {
        b = 4;
    }
    else if(a == '5')
    {
        b = 5;
    }
    else if(a == '6')
    {
        b = 6;
    }
    else if(a == '7')
    {
        b = 7;
    }
    else if(a == '8')
    {
        b = 8;
    }
    else if(a == '9')
    {
        b = 9;
    }
    else if(a == '0')
    {
        b = 0;
    }
    else if(a == 'A')
    {
        b = 10;
    }
    else if(a == 'B')
    {
        b = 11;
    }
    else if(a == 'C')
    {
        b = 12;
    }
    else if(a == 'D')
    {
        b = 13;
    }
    else if(a == 'E')
    {
        b = 14;
    }
    else if(a == 'F')
    {
        b = 15;
    }
    return b;
}

int power(int base, int exp) 
{
    int result = 1;

    if (exp < 0) 
    {
        return 0;
    }

    for (int i = 0; i < exp; i++) 
    {
        result *= base;
    }

    return result;
}


int htol(char hex[], int size)
{
    int result = 0;
    if(size < 3)
    {
        return -1;
    }
    if(hex[0] == '0')
    {
        if(hex[1] == 'x')
        {
            for(int i = 0; i < size-2; i++)
            {
                result = result + htod(hex[i + 2]) * power(16, size - i - 3);
            }
            return result;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}
