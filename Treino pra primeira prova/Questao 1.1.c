#include <stdio.h>
// Biblioteca padrão de entrada e saída. Necessária para usar printf() e scanf().

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y);
// Declaração da função que vai verificar se um ponto (x, y) está dentro do retângulo.

int main(void)
{
    // Declaração das variáveis inteiras que vamos usar.
    int x, y, x1, y1, x0, y0, retorno;

    // Solicita ao usuário as coordenadas dos vértices do retângulo
    printf("Digite os vertices superiores esquerdo (os lados menores) e superiores direito (os lados maiores) do retangulo\n");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    // x0, y0 → vértice superior esquerdo (menor valor)
    // x1, y1 → vértice inferior direito (maior valor)

    // Solicita ao usuário o ponto que será verificado
    printf("Agora digite um ponto xy qualquer q vc deseja saber se esta dentro ou nao do retangulo\n");
    scanf("%d %d", &x, &y);

    // Chama a função que verifica se o ponto está dentro do retângulo
    retorno = dentro_ret(x0, y0, x1, y1, x, y);

    // Verifica o valor retornado e exibe a mensagem apropriada
    if (retorno == 0)
    {
        printf("O ponto nao esta dentro do retangulo");
    }
    else
    {
        printf("O ponto esta dentro do retangulo");
    }
}

// Função que retorna 1 (verdadeiro) se o ponto estiver dentro do retângulo, e 0 (falso) caso contrário.
int dentro_ret(int x0, int y0, int x1, int y1, int x, int y)
{
    // Aqui verificamos se o ponto (x, y) está dentro da área delimitada pelos vértices do retângulo
    if (x0 <= x && x <= x1 && y0 <= y && y <= y1)
    {
        return 1; // Está dentro
    }
    else
    {
        return 0; // Está fora
    }
}
