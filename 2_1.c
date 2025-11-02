
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>

int main(void)
{
    printf("Range of CHAR type is from %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of UNSIGNED_CHAR type is from 0 to %u\n", UCHAR_MAX);
    printf("Range of SHORT_INT type is from %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of UNSIGNED_SHORT_INT type is from 0 to %u\n", USHRT_MAX);    
    printf("Range of INT type is from %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of UNSIGNED_INT type is from 0 to %u\n", UINT_MAX);
    printf("Range of LONG_INT type is from %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of UNSIGNED_LONG_INT type is from 0 to %lu\n", ULONG_MAX);
    
    printf("Amplitude of CHAR type is %.0f\n", pow(2,8));
    printf("Amplitude of SHORT_INT type is %.0f\n", pow(2,16));
    printf("Amplitude of INT type is %.0f\n", pow(2,16));
    printf("Amplitude of LONG_INT type is %.0f\n", pow(2,32));
    
    printf("Range of FLOAT type is from %f to %f\n", FLT_MIN, FLT_MAX);
    printf("Range of DOUBLE type is from %f to %f\n", DBL_MIN, DBL_MAX);
    printf("Range of LONG_DOUBLE type is from %Lf to %Lf\n", LDBL_MIN, LDBL_MAX);
    
    return 0;
}
