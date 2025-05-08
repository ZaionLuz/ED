#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50]; // Para armazenar o nome do aluno
    float nota1;
    float nota2;
    float media;
} Aluno;

int main(void)
{
    int n, i, novo_n;
    Aluno *turma = NULL;

    // Inicialmente, vamos alocar 1 aluno
    turma = (Aluno *)malloc(sizeof(Aluno));
    if (turma == NULL)
    {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    printf("Digite a quantidade de alunos a ser cadastrada: ");
    scanf("%d", &n);

    // Leitura dos dados dos alunos
    for (i = 0; i < n; i++)
    {
        printf("\nAluno %d:\n", i + 1);

        // Lendo nome
        printf("Digite o nome do aluno: ");
        getchar();                       // Limpa o buffer
        fgets(turma[i].nome, 50, stdin); // Lê o nome com espaço

        // Lendo as notas
        printf("Digite a primeira nota: ");
        scanf("%f", &turma[i].nota1);
        printf("Digite a segunda nota: ");
        scanf("%f", &turma[i].nota2);

        // Calculando a média
        turma[i].media = (turma[i].nota1 + turma[i].nota2) / 2;

        // Se quiser adicionar mais alunos, usa realloc
        if (i == n - 1)
        {
            printf("\nQuer adicionar mais alunos? (1 para sim, 0 para não): ");
            scanf("%d", &novo_n);

            if (novo_n == 1)
            {
                printf("Digite a quantidade de novos alunos: ");
                scanf("%d", &n);

                // Realloc para adicionar mais alunos
                turma = (Aluno *)realloc(turma, n * sizeof(Aluno));
                if (turma == NULL)
                {
                    printf("Erro ao redimensionar a memória!\n");
                    return 1;
                }
            }
        }
    }

    // Exibindo os dados dos alunos
    printf("\n--- Médias dos Alunos ---\n");
    for (i = 0; i < n; i++)
    {
        printf("Aluno %d: Nome = %sNota1 = %.2f, Nota2 = %.2f, Média = %.2f\n",
               i + 1, turma[i].nome, turma[i].nota1, turma[i].nota2, turma[i].media);
    }

    // Liberando a memória
    free(turma);
    return 0;
}
