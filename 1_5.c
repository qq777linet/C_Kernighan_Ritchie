#include <stdio.h>
 
int main(void)
{
    float fahr, celsius;
    int step = 20;
    celsius = 0;
    printf(" This is temperature table\n");
    for(int i = 0; i <= 300; i = i + step)
    {
        fahr = celsius*(9.0/5.0) + 32;
        printf ("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
