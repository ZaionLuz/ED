#include <stdio.h>
#include <stdlib.h>

float **cria_matriz(int linhas, int colunas);
float **soma_matriz(float **A, int n, int m, float **B, int o, int p);
void libera_matriz(float **A, int linhas);

int main(void)
{
    int linhas = 2, colunas = 2;

    // Criando duas matrizes 2x2
    float **A = cria_matriz(linhas, colunas);
    float **B = cria_matriz(linhas, colunas);

    // Inicializando as matrizes com valores
    A[0][0] = 1.0;
    A[0][1] = 2.0;
    A[1][0] = 3.0;
    A[1][1] = 4.0;

    B[0][0] = 5.0;
    B[0][1] = 6.0;
    B[1][0] = 7.0;
    B[1][1] = 8.0;

    // Somando as matrizes
    float **resultado = soma_matriz(A, linhas, colunas, B, linhas, colunas);

    if (resultado != NULL)
    {
        printf("Resultado da soma das matrizes:\n");
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                printf("%10.2f ", resultado[i][j]);
            }
            printf("\n");
        }

        // Liberando a memória das matrizes
        libera_matriz(resultado, linhas);
    }
    else
    {
        printf("As matrizes têm tamanhos incompatíveis para soma.\n");
    }

    // Liberando a memória das matrizes originais
    libera_matriz(A, linhas);
    libera_matriz(B, linhas);
}

float **cria_matriz(int linhas, int colunas)
{
    float **matriz = (float **)malloc(sizeof(float *) * linhas);

    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (float *)malloc(sizeof(float) * colunas);
    }

    return matriz;
}

float **soma_matriz(float **A, int n, int m, float **B, int o, int p)
{
    if (n != o || m != p)
        return NULL;

    float **soma = cria_matriz(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            soma[i][j] = A[i][j] + B[i][j];
        }
    }

    return soma;
}

void libera_matriz(float **A, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(A[i]);
    }
    free(A);
}
