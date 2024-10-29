#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // int (signed int)
    printf("Tentativa de quebrar int:\n");
    int int_max = INT_MAX;
    int int_min = INT_MIN;
    printf("  Valor de INT_MAX: %d\n", int_max);
    printf("  INT_MAX + 1: %d\n", int_max + 1);  // Deve ocorrer overflow
    printf("  Valor de INT_MIN: %d\n", int_min);
    printf("  INT_MIN - 1: %d\n\n", int_min - 1);  // Deve ocorrer underflow

    // unsigned int
    printf("Tentativa de quebrar unsigned int:\n");
    unsigned int uint_max = UINT_MAX;
    printf("  Valor de UINT_MAX: %u\n", uint_max);
    printf("  UINT_MAX + 1: %u\n", uint_max + 1);  // Overflow em unsigned int volta para 0
    unsigned int uint_min = 0;
    printf("  Valor de 0: %u\n", uint_min);
    printf("  0 - 1: %u\n\n", uint_min - 1);  // Underflow em unsigned int vai para o valor máximo

    // short int (signed short int)
    printf("Tentativa de quebrar short int:\n");
    short int short_max = SHRT_MAX;
    short int short_min = SHRT_MIN;
    printf("  Valor de SHRT_MAX: %d\n", short_max);
    printf("  SHRT_MAX + 1: %d\n", short_max + 1);  // Overflow
    printf("  Valor de SHRT_MIN: %d\n", short_min);
    printf("  SHRT_MIN - 1: %d\n\n", short_min - 1);  // Underflow

    // unsigned short int
    printf("Tentativa de quebrar unsigned short int:\n");
    unsigned short int ushort_max = USHRT_MAX;
    unsigned short int ushort_min = 0;
    printf("  Valor de USHRT_MAX: %u\n", ushort_max);
    printf("  USHRT_MAX + 1: %u\n", ushort_max + 1);  // Overflow
    printf("  Valor de 0: %u\n", ushort_min);
    printf("  0 - 1: %u\n\n", ushort_min - 1);  // Underflow

    // long int (signed long int)
    printf("Tentativa de quebrar long int:\n");
    long int long_max = LONG_MAX;
    long int long_min = LONG_MIN;
    printf("  Valor de LONG_MAX: %ld\n", long_max);
    printf("  LONG_MAX + 1: %ld\n", long_max + 1);  // Overflow
    printf("  Valor de LONG_MIN: %ld\n", long_min);
    printf("  LONG_MIN - 1: %ld\n\n", long_min - 1);  // Underflow

    // unsigned long int
    printf("Tentativa de quebrar unsigned long int:\n");
    unsigned long int ulong_max = ULONG_MAX;
    unsigned long int ulong_min = 0;
    printf("  Valor de ULONG_MAX: %lu\n", ulong_max);
    printf("  ULONG_MAX + 1: %lu\n", ulong_max + 1);  // Overflow volta para 0
    printf("  Valor de 0: %lu\n", ulong_min);
    printf("  0 - 1: %lu\n\n", ulong_min - 1);  // Underflow vai para o valor máximo

    // long long int
    printf("Tentativa de quebrar long long int:\n");
    long long int llong_max = LLONG_MAX;
    long long int llong_min = LLONG_MIN;
    printf("  Valor de LLONG_MAX: %lld\n", llong_max);
    printf("  LLONG_MAX + 1: %lld\n", llong_max + 1);  // Overflow
    printf("  Valor de LLONG_MIN: %lld\n", llong_min);
    printf("  LLONG_MIN - 1: %lld\n\n", llong_min - 1);  // Underflow

    // unsigned long long int
    printf("Tentativa de quebrar unsigned long long int:\n");
    unsigned long long int ullong_max = ULLONG_MAX;
    unsigned long long int ullong_min = 0;
    printf("  Valor de ULLONG_MAX: %llu\n", ullong_max);
    printf("  ULLONG_MAX + 1: %llu\n", ullong_max + 1);  // Overflow volta para 0
    printf("  Valor de 0: %llu\n", ullong_min);
    printf("  0 - 1: %llu\n\n", ullong_min - 1);  // Underflow vai para o valor máximo

    // long double (não faz overflow, mas pode perder precisão)
    printf("Tentativa de quebrar long double:\n");
    long double ld_max = LDBL_MAX;
    long double ld_min = LDBL_MIN;
    printf("  Valor de LDBL_MAX: %Le\n", ld_max);
    printf("  LDBL_MAX * 2: %Le\n", ld_max * 2);  // Pode resultar em "infinito"
    printf("  Valor de LDBL_MIN: %Le\n", ld_min);
    printf("  LDBL_MIN / 2: %Le\n", ld_min / 2);  // Pode perder precisão

    return 0;
}
