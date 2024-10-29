#include <stdio.h>

int main() {
    //signed char sc;
    unsigned char uc;

    /*printf("Valores de signed char (-128 a 127):\\n");
    for (sc = -128; sc <= 127; sc++) {
        printf("Valor: %d, Caractere: %c\\n", sc, sc);
    }*/

    printf("\nValores de unsigned char (0 a 255):\n");
    for (uc = 0; uc <= 255; uc++) {
        printf("Valor: %d, Caractere: %c\n", uc, uc);
    }

    return 0;
}
