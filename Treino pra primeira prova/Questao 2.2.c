#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <math.h>  // Biblioteca matemática (usada para M_PI)

void calc_esfera(float r, float *area, float *volume);
// Declaração da função que calcula a área e o volume da esfera

int main(void)
{
    float raio, area, volume; // Variáveis para armazenar o raio, a área e o volume

    printf("Digite o raio da esfera: "); // Solicita ao usuário o valor do raio
    scanf("%f", &raio);                  // Lê o valor digitado

    // Verifica se o raio é válido (deve ser positivo)
    if (raio < 0)
    {
        printf("Raio invalido!"); // Mostra erro se o raio for negativo
        return 1;                 // Encerra o programa com erro
    }

    // Chama a função que calcula a área e o volume, passando os endereços de area e volume
    calc_esfera(raio, &area, &volume);

    // Exibe os resultados
    printf("Area da superficie: %.2f\n", area);
    printf("Volume da esfera: %.2f\n", volume);

    return 0; // Fim do programa
}

void calc_esfera(float r, float *area, float *volume)
{
    // Fórmula da área da superfície da esfera: A = 4πr²
    *area = 4 * M_PI * r * r;

    // Fórmula do volume da esfera: V = (4/3)πr³
    *volume = (4.0 / 3.0) * M_PI * r * r * r;

    // O uso de ponteiros (*area e *volume) permite alterar os valores diretamente na main()
}
