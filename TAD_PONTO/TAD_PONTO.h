#ifndef __TAD_PONTO__
#define __TAD_PONTO__

/* TAD: ponto (x,y) */

/* Tipo exportado */
typedef struct
{
    float x;
    float y;
} ponto;

/* Funções exportadas */

/* Função cria
** Aloca e retorna um ponto com coordenadas (x,y)
*/
ponto *pto_cria(float x, float y);

/* Função libera
** Libera a memória de um ponto previamente criado.
*/
void pto_libera(ponto *p);

/* Função acessa
** Retorna os valores das coordenadas de um ponto
*/
void pto_acessa(ponto *p, float *x, float *y);

/* Função atribui
** Atribui novos valores às coordenadas de um ponto
*/
void pto_atribui(ponto *p, float x, float y);

/* Função distância
** Retorna a distância entre dois pontos
*/
float pto_distancia(ponto *p1, ponto *p2);

#include "TAD_PONTO.c"
#endif