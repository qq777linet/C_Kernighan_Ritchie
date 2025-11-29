//Kernighan&Ritchie 2.9

int bitcount (unsigned int x)
{
    int b;
    for (b = 0; x != 0; х &= (х-1))
    {
        b++;
    }
    return b;
}
