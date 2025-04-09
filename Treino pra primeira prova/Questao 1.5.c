#include <stdio.h> // Biblioteca padrão de entrada e saída (usada para printf e scanf)

double pi(int n); // Declaração da função que calcula a aproximação de pi

int main(void)
{
    int termos; // Variável para armazenar quantos termos o usuário quer usar na aproximação

    printf("Digite o número de termos para aproximar pi: "); // Pede ao usuário o número de termos
    scanf("%d", &termos);                                    // Lê o número digitado

    double valor_pi = pi(termos); // Chama a função 'pi' passando a quantidade de termos, e armazena o resultado

    printf("Aproximacao de pi com %d termos: %.15f\n", termos, valor_pi); // Exibe o valor aproximado de pi com 15 casas decimais

    return 0; // Finaliza o programa com sucesso
}

double pi(int n) // Função que calcula a aproximação de pi usando a série de Gregory-Leibniz
{
    double resultado = 0.0; // Variável para acumular o valor da soma
    int sinal = 1;          // Começamos com sinal positivo (+1)

    for (int i = 0; i < n; i++) // Loop que vai de 0 até n-1
    {
        resultado += sinal * (1.0 / (2 * i + 1)); // Soma ou subtrai o termo da série: 1/(2i+1)
        sinal *= -1;                              // Alterna o sinal: se era +1 vira -1, se era -1 vira +1
    }

    return 4.0 * resultado; // Multiplica o resultado final por 4, como manda a fórmula da série
}
