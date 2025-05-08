#include <stdio.h>
#include <stdlib.h>

#define N_LINHAS 4
#define N_COLUNAS 4

float **cria_matriz(int n_linhas, int n_colunas);
void libera_matriz(float **matriz, int n_linhas);
void imprime_matriz(float **matriz, int n_linhas, int n_colunas);
float **transpor_matriz(float **matriz, int n_linhas, int n_colunas);

// Tarefa de casa...
float **soma_matriz(float **matriz_a, int linhas_a, int colunas_a, float **matriz_b, int linhas_b, int colunas_b);
float **sub_matriz(float **matriz_a, int linhas_a, int colunas_a, float **matriz_b, int linhas_b, int colunas_b);
float **mult_matriz(float **matriz_a, int linhas_a, int colunas_a, float **matriz_b, int linhas_b, int colunas_b);

int main(void)
{
    float **matriz_a = cria_matriz(N_LINHAS, N_COLUNAS);
}

float **cria_matriz(int n_linhas, int n_colunas)
{
    float **mat = (float **)malloc(n_linhas * sizeof(float *));

    for (int i = 0; i < n_linhas; i++)
    {
        mat[i] = (float *)malloc(n_colunas * sizeof(float));
    }

    for(int i=0;i<n_linhas;i++)
    {
        for(int j=0;j<n_colunas;j++)
        {
            mat[i][j]=i*n_colunas+j+1;
        }
    }
    
    return mat;
}

void libera_matriz(float** matriz,int n_linhas);