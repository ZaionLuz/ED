#include <stdio.h>
#include <stdlib.h>

float **cria_matriz(int linhas, int colunas);
void preenche_matriz(float **matriz, int linhas, int colunas);
void libera_matriz(float **matriz, int linhas);
void imprime_matriz(float **matriz, int linhas, int colunas);
float **transpor_matriz(float **matriz, int linhas, int colunas);
float **soma_matriz(float **a, float **b, int linhas, int colunas);
float **sub_matriz(float **a, float **b, int linhas, int colunas);
float **multiplica_matriz(float **a, float **b, int linhas_a, int colunas_a, int colunas_b);

int main()
{
    int linhas_a = 3, colunas_a = 3;
    int linhas_b = 3, colunas_b = 3;

    if (colunas_a != linhas_b)
    {
        printf("Erro: colunas de A devem ser iguais às linhas de B para multiplicação.\n");
        return 1;
    }

    float **matriz_a = cria_matriz(linhas_a, colunas_a);
    float **matriz_b = cria_matriz(linhas_b, colunas_b);

    printf("Preencha a matriz A (%dx%d):\n", linhas_a, colunas_a);
    preenche_matriz(matriz_a, linhas_a, colunas_a);

    printf("Preencha a matriz B (%dx%d):\n", linhas_b, colunas_b);
    preenche_matriz(matriz_b, linhas_b, colunas_b);

    float **soma = soma_matriz(matriz_a, matriz_b, linhas_a, colunas_a);
    float **subtracao = sub_matriz(matriz_a, matriz_b, linhas_a, colunas_a);
    float **produto = multiplica_matriz(matriz_a, matriz_b, linhas_a, colunas_a, colunas_b);
    float **transposta_a = transpor_matriz(matriz_a, linhas_a, colunas_a);
    float **transposta_b = transpor_matriz(matriz_b, linhas_b, colunas_b);

    printf("\nMatriz A:\n");
    imprime_matriz(matriz_a, linhas_a, colunas_a);

    printf("\nMatriz B:\n");
    imprime_matriz(matriz_b, linhas_b, colunas_b);

    printf("\nSoma (A + B):\n");
    imprime_matriz(soma, linhas_a, colunas_a);

    printf("\nSubtracao (A - B):\n");
    imprime_matriz(subtracao, linhas_a, colunas_a);

    printf("\nMultiplicacao (A x B):\n");
    imprime_matriz(produto, linhas_a, colunas_b);

    printf("\nTransposta de A:\n");
    imprime_matriz(transposta_a, colunas_a, linhas_a);

    printf("\nTransposta de B:\n");
    imprime_matriz(transposta_b, colunas_b, linhas_b);

    printf("Liberando td laaaa ele\n");
    libera_matriz(matriz_a, linhas_a);
    libera_matriz(matriz_b, linhas_b);
    libera_matriz(soma, linhas_a);
    libera_matriz(subtracao, linhas_a);
    libera_matriz(produto, linhas_a);
    libera_matriz(transposta_a, colunas_a);
    libera_matriz(transposta_b, colunas_b);

    return 0;
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

void preenche_matriz(float **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void libera_matriz(float **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void imprime_matriz(float **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%10.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

float **transpor_matriz(float **matriz, int linhas, int colunas)
{
    float **transposta = cria_matriz(colunas, linhas);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            transposta[j][i] = matriz[i][j];
        }
    }
    return transposta;
}

float **soma_matriz(float **a, float **b, int linhas, int colunas)
{
    float **soma = cria_matriz(linhas, colunas);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            soma[i][j] = a[i][j] + b[i][j];
        }
    }
    return soma;
}

float **sub_matriz(float **a, float **b, int linhas, int colunas)
{
    float **sub = cria_matriz(linhas, colunas);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }
    return sub;
}

float **multiplica_matriz(float **a, float **b, int linhas_a, int colunas_a, int colunas_b)
{
    float **resultado = cria_matriz(linhas_a, colunas_b);
    for (int i = 0; i < linhas_a; i++)
    {
        for (int j = 0; j < colunas_b; j++)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas_a; k++)
            {
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return resultado;
}