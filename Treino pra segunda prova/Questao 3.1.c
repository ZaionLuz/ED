#include <stdio.h>

int negativos(int n, float *vet);

int main(void)
{
    int n, i, retorno;
    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);
    float vet[n];
    for (i = 0; i < n; i++)
    {
        printf("Digite o elemento %d do vetor ", i + 1);
        scanf("%f", &vet[i]);
    }
    retorno = negativos(n, vet);
    printf("A quantidade de numeros negativos no vetor e: %d", retorno);
}

int negativos(int n, float *vet)
{
    int negativos = 0, i;
    for (i = 0; i < n; i++)
    {
        if (vet[i] < 0)
        {
            negativos++;
        }
        else
        {
            continue;
        }
    }
    return negativos;
}