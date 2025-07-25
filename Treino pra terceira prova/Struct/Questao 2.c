#include <stdio.h>

typedef struct
{
    char nome[50];
    float preco;
    int quantidade;

} produto;

int main(void)
{
    produto p1, p2;

    printf("Digite o nome, o preco e a quantidade do produto 1\n");
    fgets(p1.nome, sizeof(p1.nome), stdin);
    scanf(" %f %d", &p1.preco, &p1.quantidade);
    fflush(stdin);

    printf("Digite o nome, o preco e a quantidade do produto 2\n");
    fgets(p2.nome, sizeof(p2.nome), stdin);
    scanf(" %f %d", &p2.preco, &p2.quantidade);

    printf("Produto 1\nNome: %sPreco: %.2f\nQuantidade: %d\n", p1.nome, p1.preco, p1.quantidade);

    printf("Produto 2:\n Nome: %sPreco: %.2f\n Quantidade: %d", p2.nome, p2.preco, p2.quantidade);
}
