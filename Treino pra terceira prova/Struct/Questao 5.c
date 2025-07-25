#include <stdio.h>

typedef struct
{
    char titulo[100];
    char diretor[50];
    int ano;
} Filme;

int main(void)
{
    int n;
    printf("Quantos filmes deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); // limpa o '\n' do buffer

    Filme filmes[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nFilme %d:\n", i + 1);

        printf("Titulo: ");
        fgets(filmes[i].titulo, sizeof(filmes[i].titulo), stdin);
        for (int j = 0; filmes[i].titulo[j] != '\0'; j++)
        {
            if (filmes[i].titulo[j] == '\n')
            {
                filmes[i].titulo[j] = '\0';
                break;
            }
        }

        printf("Diretor: ");
        fgets(filmes[i].diretor, sizeof(filmes[i].diretor), stdin);
        for (int j = 0; filmes[i].diretor[j] != '\0'; j++)
        {
            if (filmes[i].diretor[j] == '\n')
            {
                filmes[i].diretor[j] = '\0';
                break;
            }
        }

        printf("Ano: ");
        scanf("%d", &filmes[i].ano);
        getchar(); // limpa o \n depois de ler o ano
    }

    printf("\n=== Lista de Filmes Cadastrados ===\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nFilme %d:\n", i + 1);
        printf("Titulo: %s\n", filmes[i].titulo);
        printf("Diretor: %s\n", filmes[i].diretor);
        printf("Ano: %d\n", filmes[i].ano);
    }
}
