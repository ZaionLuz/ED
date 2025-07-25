#include <stdio.h>

typedef struct
{
    char nome[50];
    float nota1;
    float nota2;
    float media;
} aluno;

int main(void)
{
    int tamanho;
    printf("Digite quantos alunos terao\n");
    scanf("%d", &tamanho);

    aluno a[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o nome a nota 1 e 2 do aluno %d ", i + 1);
        scanf(" %s %f %f", a[i].nome, &a[i].nota1, &a[i].nota2);
        a[i].media = (a[i].nota1 + a[i].nota2) / 2;
    }

    printf("\nLista de alunos e suas médias:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%s - Média: %.2f\n", a[i].nome, a[i].media);
    }
}