#include <stdio.h>

int pares(int n, int *vet);

int main(void)
{
    int n, i, retorno;
    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);
    int vet[n];
    for (i = 0; i < n; i++)
    {
        printf("Digite o elemento %d do vetor ", i + 1);
        scanf("%d", &vet[i]);
    }
    retorno = pares(n, vet);
    printf("A quantidade de numeros pares no vetor e: %d", retorno);
}

int pares(int n, int *vet)
{
    int i, pares = 0;
    for (i = 0; i < n; i++)
    {
        if (vet[i] % 2 == 0)
        {
            pares++;
        }
        else
        {
            continue;
        }
    }
    return pares;
}