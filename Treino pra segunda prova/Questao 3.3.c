#include <stdio.h>

void inverte(int n, int *vet);

int main(void)
{
    int n, i;
    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);
    int vet[n];
    for (i = 0; i < n; i++)
    {
        printf("Digite o elemento %d do vetor ", i + 1);
        scanf("%d", &vet[i]);
    }
    inverte(n, vet);
    printf("\nVetor invertido:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void inverte(int n, int *vet)
{
    int i, aux;
    for (i = 0; i < n / 2; i++)
    {
        aux = vet[i];
        vet[i] = vet[n - 1 - i];
        vet[n - 1 - i] = aux;
    }
}