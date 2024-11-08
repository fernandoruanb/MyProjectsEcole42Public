#include <stdio.h>

int main() {
    // Exemplo de nova linha (\n)
    printf("Exemplo de nova linha:\n\nPrimeira linha\nSegunda linha\n");

    // Exemplo de tabulação horizontal (\t)
    printf("Exemplo de tabulação horizontal:\t\nColuna 1\tColuna 2\tColuna 3\n");

    // Exemplo de barra invertida (\\)
    printf("Exemplo de barra invertida:\nC:\\Program Files\\MyApp\n");

    // Exemplo de aspas duplas (\")
    printf("Exemplo de aspas duplas:\"\nEle disse: \"Olá, tudo bem?\"\n");

    // Exemplo de aspas simples (\')
    printf("Exemplo de aspas simples:\'\nÉ assim que se usa a aspas simples: \'caractere\'\n");

    // Exemplo de alerta sonoro (\a)
    printf("Exemplo de alerta sonoro:\a\n");
    printf("\a");  // Dependendo do sistema, você pode ouvir um som

    // Exemplo de backspace (\b)
    printf("Exemplo de backspace:\b\nHello, Worlb\bld!\n");  // Apaga o "b" antes do "d"

    // Exemplo de retorno de carro (\r)
    printf("Exemplo de retorno de carro:\r\nInício da linha\rSubstituindo\n"); // "Início da linha" é substituído

    // Exemplo de tabulação vertical (\v)
    printf("Exemplo de tabulação vertical:\v\nLinha 1\vLinha 2\vLinha 3\n");

    // Exemplo de alimentação de formulário (\f)
    printf("Exemplo de alimentação de formulário:\f\nPrimeira parte\fSegunda parte\n");

    // Exemplo de caractere nulo (\0)
    char str[] = "Hello\\0World";
    printf("Exemplo de caractere nulo:\0\n%s\n", str); // Apenas "Hello" será exibido

    return 0;
}

