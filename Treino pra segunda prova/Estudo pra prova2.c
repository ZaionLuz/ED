#include <stdio.h>
#include <stdlib.h>

float **cria_matriz(int linhas, int colunas);
float **mult_matriz(float **A, int n, int m, float **B, int o, int p);
void libera_matriz(float **A, int linhas);

int main(void)
{
    int linhas = 2, colunas = 2;

    float **A = cria_matriz(linhas, colunas);
    float **B = cria_matriz(linhas, colunas);

    // Preenchendo matriz A
    A[0][0] = 1.0;
    A[0][1] = 2.0;
    A[1][0] = 3.0;
    A[1][1] = 4.0;

    // Preenchendo matriz B
    B[0][0] = 5.0;
    B[0][1] = 6.0;
    B[1][0] = 7.0;
    B[1][1] = 8.0;

    // Multiplicação elemento a elemento
    float **resultado = mult_matriz(A, linhas, colunas, B, linhas, colunas);

    if (resultado != NULL)
    {
        printf("Resultado da multiplicação elemento a elemento:\n");
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                printf("%8.2f ", resultado[i][j]);
            }
            printf("\n");
        }
        libera_matriz(resultado, linhas);
    }
    else
    {
        printf("Erro: Matrizes incompatíveis para multiplicação.\n");
    }

    libera_matriz(A, linhas);
    libera_matriz(B, linhas);
}

float **cria_matriz(int linhas, int colunas)
{
    float **mat = (float **)malloc(sizeof(float *) * linhas);

    for (int i = 0; i < linhas; i++)
    {
        mat[i] = (float *)malloc(sizeof(float) * colunas);
    }

    return mat;
}

float **mult_matriz(float **A, int n, int m, float **B, int o, int p)
{
    if (n != o || m != p)
        return NULL;

    float **mult = cria_matriz(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mult[i][j] = A[i][j] * B[i][j];
        }
    }

    return mult;
}

void libera_matriz(float **A, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(A[i]);
    }
    free(A);
}