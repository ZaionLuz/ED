#include <stdio.h>
// Biblioteca padrão de entrada e saída. Usada para printf() e scanf().

int primo(int n);
// Declaração da função que vai verificar se o número é primo.

int main(void)
{
    int n, retorno; // Declaração das variáveis

    printf("Digite um numero para saber se ele e primo ou nao\n");
    scanf("%d", &n); // Lê o número digitado pelo usuário

    retorno = primo(n); // Chama a função para verificar se é primo

    // Interpreta o retorno e mostra o resultado
    if (retorno == 0)
    {
        printf("O numero: %d nao e primo", n);
    }
    else
    {
        printf("O numero: %d e primo", n);
    }
}
