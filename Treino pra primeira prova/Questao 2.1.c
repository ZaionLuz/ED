#include <stdio.h> // Biblioteca padrão de entrada/saída
#include <math.h>  // Biblioteca matemática (usada para sqrt)

int raizes(float a, float b, float c, float *x1, float *x2);
// Declaração da função que calcula as raízes e armazena os resultados nos ponteiros x1 e x2

int main(void)
{
    float a, b, c, x1, x2; // Coeficientes da equação (a, b, c) e variáveis para armazenar as raízes
    int retorno;           // Variável para guardar o tipo de retorno da função raizes

    printf("Digite os coeficientes a, b e c:\n"); // Solicita os coeficientes ao usuário
    scanf("%f %f %f", &a, &b, &c);                // Lê os coeficientes digitados

    retorno = raizes(a, b, c, &x1, &x2); // Chama a função raizes passando os endereços de x1 e x2

    // Testa o valor de retorno e imprime a mensagem correspondente
    if (retorno == 1)
    {
        printf("A equacao nao possui raizes reais.\n"); // delta < 0
    }
    else if (retorno == 2)
    {
        printf("A equacao possui uma raiz real: x1 = %.2f\n", x1); // delta == 0
    }
    else if (retorno == 3)
    {
        printf("A equacao possui duas raizes reais: x1 = %.2f e x2 = %.2f\n", x1, x2); // delta > 0
    }

    return 0; // Finaliza o programa
}

int raizes(float a, float b, float c, float *x1, float *x2)
{
    float delta = b * b - 4 * a * c; // Fórmula do discriminante (delta = b² - 4ac)

    if (delta < 0)
    {
        return 1; // Se delta for negativo, não existem raízes reais
    }
    else if (delta == 0)
    {
        *x1 = -b / (2 * a); // Raiz única (x = -b/2a), usa ponteiro para alterar valor fora da função
        return 2;           // Indica que só existe uma raiz real
    }
    else
    {
        *x1 = (-b + sqrt(delta)) / (2 * a); // Primeira raiz
        *x2 = (-b - sqrt(delta)) / (2 * a); // Segunda raiz
        return 3;                           // Indica que existem duas raízes reais
    }
}
