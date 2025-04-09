#include <stdio.h>
// Biblioteca padrão de entrada e saída. Usamos ela para usar printf() e scanf().

long int fibonacci(long int n);
// Declaração da função que vai calcular o n-ésimo termo da sequência de Fibonacci.

int main(void)
{
    int n;            // Variável que armazena qual termo da sequência o usuário quer ver
    long int retorno; // Variável que vai guardar o resultado da função fibonacci()

    // Mensagem pedindo o termo desejado ao usuário
    printf("Digite o termo da sequencia de fibonacci que vc deseja saber\n");
    scanf("%d", &n); // Lê o número digitado pelo usuário

    // Chamada da função fibonacci, que vai calcular o termo desejado
    retorno = fibonacci(n);

    // Mostra o resultado final
    printf("O termo %d da sequencia de fibonacci e %ld", n, retorno);

    return 0; // Indica que o programa terminou corretamente
}

// Função que calcula o n-ésimo termo da sequência de Fibonacci usando recursão
long int fibonacci(long int n)
{
    // Caso base: os dois primeiros termos da sequência são conhecidos
    if (n <= 1)
        return n; // fibonacci(0) = 0 e fibonacci(1) = 1

    // Chamada recursiva: a função chama a si mesma duas vezes
    // Soma os dois termos anteriores da sequência
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
