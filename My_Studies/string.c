#include <stdio.h>

int main() {
    // 1. Constante string (literal) usando `const char *`
    const char *constantStr = "Hello, world!";
    printf("Constant string (literal): %s\n", constantStr);

    // Teste: tentando modificar a string literal
    // constantStr[0] = 'J'; // Descomente para ver o erro de compilação (imutável)

    // 2. Ponteiro para string literal sem `const` (geralmente deve ser evitado)
    char *nonConstStr = "Hello, C!";
    printf("String literal sem `const`: %s\n", nonConstStr);

    // Teste: tentando modificar a string literal (comportamento indefinido)
     //nonConstStr[0] = 'J'; // Pode compilar, mas causará erro de execução ou comportamento indefinido

    // 3. Array de caracteres modificável
    char modifiableArray[] = "Hello, Array!";
    printf("Array de caracteres antes de modificar: %s\n", modifiableArray);

    // Modificando o array de caracteres
    modifiableArray[0] = 'J';
    printf("Array de caracteres depois de modificar: %s\n", modifiableArray);

    return 0;
}

