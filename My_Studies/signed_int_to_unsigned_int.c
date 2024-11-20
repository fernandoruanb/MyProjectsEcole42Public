#include <stdio.h>

int main() {
    signed int a;         // Valor negativo
    unsigned int b;         // Atribuindo valor de a a b (conversão automática)

    a = -10;
    b = a;
    printf("Valor de a (signed int): %d\n %u\n", a, b);
    printf("Valor de b (unsigned int): %u\n", b);  // Valor de b será grande devido à conversão

    return 0;
}

