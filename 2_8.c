//Kernighan&Ritchie 2.8

int rightrot(unsigned int x, unsigned int n)
{

    unsigned int temp = x<<(sizeof(unsigned int)*8 -n);
    unsigned int temp_2 = x>>n;
    x = temp|temp_2;
    return x;
}
