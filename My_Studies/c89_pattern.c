#include <stdio.h>

void teste_c89() {
    int x;
    x = 10;
    x += 10;

    int y;
    y = 30;
    printf("x: %d, y: %d\n", x, y);
}

int main() {
    teste_c89();
    return 0;
}
