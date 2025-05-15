#include <stdio.h>
#include <stdlib.h>

float **cria_matriz(int linhas, int colunas);
float **soma_matriz(float **A, int n, int m, float **B, int o, int p);
void libera_matriz(float **A, int linhas);

int main(void)
{
    int linhas = 2, colunas = 3;

    float **matA = cria_matriz(linhas, colunas);
    float **matB = cria_matriz(linhas, colunas);

    // Preenche matA
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            matA[i][j] = i + j;

    // Preenche matB
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            matB[i][j] = (i + 1) * j;

    float **matSoma = soma_matriz(matA, linhas, colunas, matB, linhas, colunas);

    if (matSoma == NULL)
    {
        printf("Nao foi possivel somar as matrizes\n");
        libera_matriz(matA, linhas);
        libera_matriz(matB, linhas);
        return 1;
    }

    // Imprime matriz soma
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%.2f ", matSoma[i][j]);
        }
        printf("\n");
    }

    libera_matriz(matA, linhas);
    libera_matriz(matB, linhas);
    libera_matriz(matSoma, linhas);
}

float **cria_matriz(int linhas, int colunas)
{
    float **mat = (float **)malloc(sizeof(float *) * linhas);

    if (!mat)
    {
        printf("N alocou");
        return NULL;
    }

    for (int i = 0; i < linhas; i++)
    {

        mat[i] = (float *)malloc(sizeof(float) * colunas);
        if (!mat[i])
        {
            printf("Erro: Nao alocou linha %d\n", i);
            // libera as linhas já alocadas antes de retornar
            for (int j = 0; j < i; j++)
                free(mat[j]);
            free(mat);
            return NULL;
        }
    }

    return mat;
}

float **soma_matriz(float **A, int n, int m, float **B, int o, int p)
{
    if (n != o || m != p)
    {
        printf("Impossivel");
        return NULL;
    }

    float **soma = cria_matriz(n, m);

    if (!soma)
    {
        printf("N alocou");
        return NULL;
    }

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