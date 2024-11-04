#include <stdio.h>

int main() {
    register int x = 10;

    // Tentativa de obter o endereço da variável 'x'
    int *ptr = &x;  // Isso causará um erro de compilação

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", (void *)ptr);

    return 0;
}
