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
        printf("O numero: %d nao e primo\n", n);
    }
    else
    {
        printf("O numero: %d e primo\n", n);
    }

    return 0;
}

// Função que verifica se um número é primo
int primo(int n)
{
    if (n <= 1)
        return 0; // Números menores ou iguais a 1 não são primos

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0; // Se for divisível por algum número além de 1 e ele mesmo, não é primo
    }

    return 1; // Se passou por todos os testes, é primo
}
