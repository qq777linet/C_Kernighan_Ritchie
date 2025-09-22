#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0; 
    upper = 300; 
    step = 20; 
    fahr = lower;
    printf(" This is temperature table\n");
    while (fahr <= upper) 
    {
        fahr = celsius*(9.0/5.0) + 32;
        printf ("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
