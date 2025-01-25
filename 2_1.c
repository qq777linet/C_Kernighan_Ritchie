#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    

    printf("signed char: %d до %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 до %u\n", UCHAR_MAX);

    printf("signed short: %d до %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 до %u\n", USHRT_MAX);

    printf("signed int: %d до %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: 0 до %u\n", UINT_MAX);

    printf("signed long: %ld до %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 до %lu\n", ULONG_MAX);

    printf("signed long long: %lld до %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long: 0 до %llu\n", ULLONG_MAX);

    printf("signed char: %d до %d\n", -(1 << (sizeof(char) * 8 - 1)), (1 << (sizeof(char) * 8 - 1)) - 1);
    printf("unsigned char: 0 до %u\n", (1U << (sizeof(char) * 8)) - 1);

    printf("signed short: %d до %d\n", -(1 << (sizeof(short) * 8 - 1)), (1 << (sizeof(short) * 8 - 1)) - 1);
    printf("unsigned short: 0 до %u\n", (1U << (sizeof(short) * 8)) - 1);

    printf("signed int: %d до %d\n", -(1 << (sizeof(int) * 8 - 1)), (1 << (sizeof(int) * 8 - 1)) - 1);
    printf("unsigned int: 0 до %u\n", (1U << (sizeof(int) * 8)) - 1);

    printf("signed long: %ld до %ld\n", -(1L << (sizeof(long) * 8 - 1)), (1L << (sizeof(long) * 8 - 1)) - 1);
    printf("unsigned long: 0 до %lu\n", (1UL << (sizeof(long) * 8)) - 1);

    printf("signed long long: %lld до %lld\n", -(1LL << (sizeof(long long) * 8 - 1)), (1LL << (sizeof(long long) * 8 - 1)) - 1);
    printf("unsigned long long: 0 до %llu\n", (1ULL << (sizeof(long long) * 8)) - 1);

    printf("float: от %e до %e\n", FLT_MIN, FLT_MAX);
    printf("double: от %e до %e\n", DBL_MIN, DBL_MAX);
    printf("long double: от %Le до %Le\n", LDBL_MIN, LDBL_MAX);
    return 0;
}
