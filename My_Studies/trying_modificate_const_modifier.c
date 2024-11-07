#include <stdio.h>

int main() {
    const int num = 10;  // Variável constante
    printf("Valor original de num: %d\n", num);

    // Fazendo um cast para obter o endereço de 'num' em um ponteiro não-constante
    int *ptr = (int *)&num;

    // Modificando o valor de num usando o ponteiro
    *ptr = 20;

    // Exibindo o valor alterado de num
    printf("Valor de num após modificação pelo ponteiro: %d\n", num);

    return 0;
}

