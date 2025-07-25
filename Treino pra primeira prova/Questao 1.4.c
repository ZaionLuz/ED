#include <stdio.h> // Biblioteca padrão de entrada e saída (usada para printf e scanf)

int soma_impares(int n); // Declaração da função que vai somar os n primeiros números ímpares

int main(void)
{
    int n, retorno; // 'n' é a quantidade de ímpares que o usuário quer somar, 'retorno' guarda o resultado da função

    printf("Digite a quantidade de numeros impares a serem somados\n"); // Pede ao usuário a quantidade de ímpares
    scanf("%d", &n);                                                    // Lê o valor digitado pelo usuário e armazena em 'n'

    retorno = soma_impares(n); // Chama a função 'soma_impares' e guarda o resultado em 'retorno'

    printf("Resultado:\n%d", retorno); // Mostra o resultado da soma na tela

    return 0; // Finaliza o programa com sucesso
}

int soma_impares(int n) // Função que retorna a soma dos n primeiros números ímpares
{
    int soma = 0;  // Variável que vai acumular a soma dos números ímpares
    int count = 0; // Contador para saber quantos ímpares já foram somados
    int i = 1;     // Começamos com 1, que é o primeiro número ímpar

    while (count < n) // Continua enquanto ainda não somamos 'n' números ímpares
    {
        if (i % 2 != 0) // Verifica se o número atual 'i' é ímpar (resto da divisão por 2 diferente de 0)
        {
            soma += i; // Soma o número ímpar na variável 'soma'
            count++;   // Incrementa o contador, pois já somamos mais um ímpar
        }
        i++; // Vai para o próximo número
    }

    return soma; // Retorna o valor final da soma dos n primeiros ímpares
}
