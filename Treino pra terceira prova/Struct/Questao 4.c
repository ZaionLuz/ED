#include <stdio.h>

typedef struct
{
    char titulo[100];
    char autor[50];
    int ano;
} livro;

int main(void)
{
    livro l;

    printf("Digite o titulo do livro:\n");
    fgets(l.titulo, sizeof(l.titulo), stdin);

    printf("Digite o autor do livro:\n");
    fgets(l.autor, sizeof(l.autor), stdin);

    printf("Digite o ano do livro:\n");
    scanf("%d", &l.ano);

    printf("\nTitulo: %sAutor: %sAno: %d\n", l.titulo, l.autor, l.ano);
}