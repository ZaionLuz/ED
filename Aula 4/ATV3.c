#include <stdio.h>
int main()
{
    int tamanho;
    printf("Digite o tamanho do vetor\n");
    scanf("%d", &tamanho);
    int vetor[tamanho], buscador, i;
    for (i = 0; i < tamanho; i++)
    {
        printf("Digite o numero %d ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("\nAgora digite um numero que vc deseja saber se pertence ou n ao vetor\n");
    scanf("%d", &buscador);
    for (i = 0; i < tamanho && vetor[i] <= buscador; i++)
    {
        if (buscador == vetor[i])
        {
            printf("Encontrado na posicao %d", i);
            break;
        }
        else
        {
            printf("Nao encontrado na posicao %d\n", i);
        }
    }
    return 0;
}