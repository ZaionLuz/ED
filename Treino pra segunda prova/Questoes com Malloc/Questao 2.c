#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, soma = 0;
    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    printf("Soma dos valores: %d\n", soma);

    free(vetor);
}