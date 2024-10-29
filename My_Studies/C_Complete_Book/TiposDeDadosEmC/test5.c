#include <stdio.h>

int main() {
    signed int a = -10;         // Valor negativo
    unsigned int b = a;         // Atribuindo valor de a a b (conversão automática)

    printf("Valor de a (signed int): %d\n", a);
    printf("Valor de b (unsigned int): %u\n", b);  // Valor de b será grande devido à conversão

    return 0;
}

