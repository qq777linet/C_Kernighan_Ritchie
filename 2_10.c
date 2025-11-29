//Kernighan&Ritchie 2.10

char lower(char a)
{
    a = (a >= 65 && a <= 90)?(a + 32):(a);
    return a;
}
