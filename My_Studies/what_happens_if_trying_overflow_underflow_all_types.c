#include <stdio.h>
#include <limits.h>

int main() {
    // Testando os limites dos tipos básicos
    printf("Limites de diferentes tipos em C:\n\n");

    // int
    printf("int:\\n");
    printf("  Valor mínimo: %d\n", INT_MIN);     // Valor mínimo de int
    printf("  Valor máximo: %d\n", INT_MAX);     // Valor máximo de int
    printf("  Tamanho de int: %zu bytes\n\n", sizeof(int));

    // unsigned int
    printf("unsigned int:\n");
    printf("  Valor máximo: %u\n", UINT_MAX);    // Valor máximo de unsigned int
    printf("  Tamanho de unsigned int: %zu bytes\n\n", sizeof(unsigned int));

    // short
    printf("short:\n");
    printf("  Valor mínimo: %d\n", SHRT_MIN);    // Valor mínimo de short
    printf("  Valor máximo: %d\n", SHRT_MAX);    // Valor máximo de short
    printf("  Tamanho de short: %zu bytes\n\n", sizeof(short));

    // unsigned short
    printf("unsigned short:\n");
    printf("  Valor máximo: %u\n", USHRT_MAX);   // Valor máximo de unsigned short
    printf("  Tamanho de unsigned short: %zu bytes\n\n", sizeof(unsigned short));

    // long
    printf("long:\n");
    printf("  Valor mínimo: %ld\n", LONG_MIN);   // Valor mínimo de long
    printf("  Valor máximo: %ld\n", LONG_MAX);   // Valor máximo de long
    printf("  Tamanho de long: %zu bytes\n\n", sizeof(long));

    // unsigned long
    printf("unsigned long:\n");
    printf("  Valor máximo: %lu\n", ULONG_MAX);  // Valor máximo de unsigned long
    printf("  Tamanho de unsigned long: %zu bytes\n\n", sizeof(unsigned long));

    // long long
    printf("long long:\n");
    printf("  Valor mínimo: %lld\n", LLONG_MIN); // Valor mínimo de long long
    printf("  Valor máximo: %lld\n", LLONG_MAX); // Valor máximo de long long
    printf("  Tamanho de long long: %zu bytes\n\n", sizeof(long long));

    // unsigned long long
    printf("unsigned long long:\n");
    printf("  Valor máximo: %llu\n", ULLONG_MAX); // Valor máximo de unsigned long long
    printf("  Tamanho de unsigned long long: %zu bytes\n\n", sizeof(unsigned long long));

    return 0;
}
