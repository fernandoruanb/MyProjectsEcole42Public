#include <stdio.h>

void testePrecisaoSimples() {
    float valoresFloat[] = {1.0f / 3.0f, 1.0f / 7.0f, 1.0f / 9.0f, 1.0f / 11.0f};
    double valoresDouble[] = {1.0 / 3.0, 1.0 / 7.0, 1.0 / 9.0, 1.0 / 11.0};
    int i;

    printf("Comparação de precisão entre float e double:\n");
    for (i = 0; i < 4; i++) {
        printf("Valor %d:\n", i + 1);
        printf("  Float : %.20f\n", valoresFloat[i]);
        printf("  Double: %.20lf\n\n", valoresDouble[i]);
    }
}

int main() {
    testePrecisaoSimples();
    return 0;
}
