#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float media = 0;
    int i, n;
    printf("Digite a quantidade de alunos\n");
    scanf("%d", &n);

    float *vetor = (float *)malloc(n * sizeof(float));

    if (vetor == NULL)
    {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Aluno %d ", i + 1);
        scanf("%f", &vetor[i]);
        media += vetor[i];
    }

    media = media / n;

    printf("Media: %.2f", media);

    free(vetor);
}