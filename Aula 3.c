#include <stdio.h>

int main()
{

    // exercício 1: página 25 do livro (convertendo altura de metros para pés e polegadas)
    int f;   // altura em pés
    float p; // altura em polegadas
    float h; // altura em metros

    // recebendo a altura
    printf("Digite a altura em metros: ");
    scanf("%f", &h);

    // calculando a altura em pés e polegadas
    h = 100 * h;                // convertendo para centimetros
    f = (int)(h / 30.48);       // calcula o numero de pés
    p = (h - f * 30.48) / 2.54; // calcula as polegadas

    // exibindo a altura
    printf("ALTURA\n PES: %dft\n POLEGADAS: %.lfpol\n", f, p);

    // exercício 2: macros (exibindo o maior entre dois valores)
    int a, b;
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    int maximo = a > b ? a : b; // usando ;operador ternário
    printf("O número maior é: %d", maximo);

    return 0;
}