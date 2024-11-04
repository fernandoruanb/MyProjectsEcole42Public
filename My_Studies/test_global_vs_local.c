#include <stdio.h>

int count = 10; // Variável global

void teste_count() {
    int count = 20; // Variável local com o mesmo nome
    printf("Valor de count dentro da função: %d\n", count);
}

int main() {
    printf("Valor de count no escopo global: %d\n", count);
    teste_count();
    return 0;
}
