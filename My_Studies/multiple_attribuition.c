#include <stdio.h>

int main(void) {
    int a, b, c;

    a = b = c = 10;  // Atribuição múltipla: c recebe 10, depois b, e finalmente a

    printf("Valores após atribuição múltipla:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    // Exemplo de atribuição com diferentes valores
    a = 5;
    b = 15;
    c = (a = 20, b = a + 5);  // Atribui 20 a 'a', e 'c' recebe a + 5

    printf("\nValores após atribuição com diferentes valores:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}
