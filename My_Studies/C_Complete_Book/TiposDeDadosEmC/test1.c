#include <stdio.h>

int main() {
    float f = 12345.6789012345f;  // Um número com mais de 7 dígitos
    double d = 12345.678901234567890;  // Um número com mais de 15 dígitos

    printf("Valor de float: %.10f\n", f);  // Exibe 10 casas decimais
    printf("Valor de double: %.17f\n", d); // Exibe 17 casas decimais

    return 0;
}
