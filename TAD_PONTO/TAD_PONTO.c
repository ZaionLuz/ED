#include "TAD_PONTO.h"
#include <stdlib.h>
#include <math.h>

/* Função Cria
** Aloca e retorna um ponto com coordenadas (x, y).
*/
ponto *pto_cria(float x, float y)
{
    ponto *novo_ponto = (ponto *)malloc(sizeof(ponto));

    if (novo_ponto == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }
    novo_ponto->x = x;
    novo_ponto->y = y;

    return novo_ponto;
}

/* Função libera
** Libera a memória de um ponto previamente criado.
*/
void pto_libera(ponto *p)
{
    free(p);
}

/* Função acessa
** Retorna os valores das coordenadas de um ponto
*/
void pto_acessa(ponto *p, float *x, float *y)
{
    *x = p->x;
    *y = p->y;
}

/* Função atribui
** Atribui novos valores às coordenadas de um ponto
*/
void pto_atribui(ponto *p, float x, float y)
{
    p->x = x;
    p->y = y;
}

/* Função distância
** Retorna a distância entre dois pontos
*/
float pto_distancia(ponto *p1, ponto *p2)
{
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt((dx * dx) + (dy * dy));
}