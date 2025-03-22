#include <stdio.h>
int variavel = 100; // global

void imprime(void);

int main()
{
    printf("Endereço: %x\n", &variavel); // representação em hexadecimal do endereço
    printf("Valor: %d\n", variavel);
    imprime();
    return 0;
}

void imprime(void)
{
    int variavel2 = 1000;
    printf("Endereço: %x\n", &variavel2);
    printf("Valor soma variável + variável2: %d\n", variavel + variavel2);
    printf("Distância entre variavel1 e variavel2: %d\n", &variavel2 - &variavel);
}