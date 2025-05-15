#include <stdio.h>
#include <stdlib.h>

float **cria_matriz(int linhas, int colunas);
void imprime_matriz(float **matriz, int linhas, int colunas);
void preenche_matriz(float **matriz, int linhas, int colunas);
int simetrica(float **matriz, int linhas, int colunas);
void libera_matriz(float **matriz, int linhas);

int main(void)
{
    int linhas, colunas;
    printf("Quantas linhas e colunas terao?\n");
    scanf("%d %d", &linhas, &colunas);

    printf("Criando a matriz\n");
    float **matriz = cria_matriz(linhas, colunas);

    printf("\nPreencha a matriz\n");
    preenche_matriz(matriz, linhas, colunas);

    printf("Imprimindo a matriz\n");
    imprime_matriz(matriz, linhas, colunas);

    printf("Verificando se e simetrica e quadrada...\n");
    if (simetrica(matriz, linhas, colunas))
        printf("A matriz e quadrada e simetrica.\n");
    else
        printf("A matriz NAO e quadrada e simetrica.\n");

    printf("Liberando a memoria\n");
    libera_matriz(matriz, linhas);
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

void preenche_matriz(float **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Digite o elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void imprime_matriz(float **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%10.2f", matriz[i][j]);
        }
        printf("\n");
    }
}

int simetrica(float **matriz, int linhas, int colunas)
{
    if (linhas != colunas)
        return 0; // Não é quadrada, logo não pode ser simétrica

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (matriz[i][j] != matriz[j][i])
                return 0;
        }
    }
    return 1;
}

void libera_matriz(float **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
