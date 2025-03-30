#include <stdio.h>

// função pra verificar se o numero é primo.
int ehPrimo(int num)
{
    if (num < 2) // numeros menores q 2 nao sao primos
        return 0;
    for (int i = 2; i * i <= num; i++) /* // esse loop percorre os possíveis divisores de 'num' até sua raiz quadrada
                                            reduzindo a quantidade de iterações necessárias.*/
    {
        if (num % i == 0) // se for divisel por i ele n e primo ent ja volta o 0 instantaneamente.
            return 0;
    }
    return 1;
}

int main()
{
    int tamanho;
    printf("Digite o tamanho do vetor\n");
    scanf("%d", &tamanho);

    int vetor[tamanho], i, primos = 0;

    for (i = 0; i < tamanho; i++)
    {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < tamanho; i++)
    {
        if (!ehPrimo(vetor[i]))
            continue;       // se n for primo pula pra prox iteracao.
        primos += vetor[i]; // soma apenas os primos.
    }
    printf("Soma de todos os primos: %d", primos);
    return 0;
}