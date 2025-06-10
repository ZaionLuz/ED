#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int mat;
    char nome[81];
    char end[121];
    char tel[21];
} Aluno;

void inicializa(int n, Aluno **tab);      // inicializa a tabela com NULL em tudo
void preenche(int n, Aluno **tab, int i); // preenche a tabela com os dados de cada aluno
void retira(int n, Aluno **tab, int i);   // libera a memoria usada dinamicamente e deixa a memoria restante como nula
void imprime(int n, Aluno **tab, int i);  // imprime os dados de cada aluno
void imprime_tudo(int n, Aluno **tab);    // imprime todos os alunos da lista com seus dados

#include <stdio.h>

int main(void)
{
    Aluno *tab[10];
    inicializa(10, tab);

    preenche(10, tab, 0);
    preenche(10, tab, 1);
    preenche(10, tab, 2);

    imprime_tudo(10, tab);

    retira(10, tab, 0);
    retira(10, tab, 1);
    retira(10, tab, 2);
}

void inicializa(int n, Aluno **tab)
{
    for (int i = 0; i < n; i++)
    {
        tab[i] = NULL;
    }
}

void preenche(int n, Aluno **tab, int i)
{
    if (i < 0 || i >= n)
    {
        printf("Indice fora do limite do vetor\n");
        exit(1);
    }

    if (tab[i] == NULL)
    {
        tab[i] = (Aluno *)malloc(sizeof(Aluno));

        printf("Entre com a matricula\n");
        scanf("%d", &tab[i]->mat);
        getchar();

        printf("Entre com o Nome\n");
        scanf("%80[^\n]", tab[i]->nome);
        getchar();

        printf("Digite o endereço do aluno\n");
        scanf("%120[^\n]", tab[i]->end);
        getchar();

        printf("Digite o telefone do aluno\n");
        scanf("%20[^\n]", tab[i]->tel);
        getchar();
    }
}

void retira(int n, Aluno **tab, int i)
{
    if (i < 0 || i >= n)
    {
        printf("Indice fora do limite do vetor\n");
        exit(2);
    }

    if (tab[i] != NULL)
    {
        free(tab[i]);
        tab[i] = NULL;
    }
}

void imprime(int n, Aluno **tab, int i)
{
    if (i < 0 || i >= n)
    {
        printf("Indice fora do limite do vetor\n");
        exit(3);
    }

    if (tab[i] != NULL)
    {
        printf("MATRICULA: %d\n", tab[i]->mat);
        printf("NOME: %s\n", tab[i]->nome);
        printf("ENDERECO: %s\n", tab[i]->end);
        printf("TELEFONE: %s\n", tab[i]->tel);
    }
}

void imprime_tudo(int n, Aluno **tab)
{
    for (int i = 0; i < n; i++)
        imprime(n, tab, i);
}