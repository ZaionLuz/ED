#include <stdio.h>

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

int main()
{
    Pessoa p;

    printf("Digite o nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);

    printf("Digite a idade: ");
    scanf("%d", &p.idade);

    printf("\nDados da pessoa:\n");
    printf("Nome: %s", p.nome);
    printf("Idade: %d\n", p.idade);

    return 0;
}
