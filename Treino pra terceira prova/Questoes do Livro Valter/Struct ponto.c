#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} ponto;

void imprime(ponto *p);
ponto *criar_ponto();
void ler_ponto(ponto *p);
float distancia(ponto *p1, ponto *p2);
int main(void)
{
    // crio os pontos
    ponto *p1 = criar_ponto();
    ponto *p2 = criar_ponto();

    // atribuo o valor dos pontos e imprimo cada um
    ler_ponto(p1);
    imprime(p1);
    ler_ponto(p2);
    imprime(p2);

    // imprimo a distancia
    printf("A distancia entre os pontos fornecidos e: %.2f", distancia(p1, p2));

    // libero os pontos
    free(p1);
    free(p2);
}

ponto *criar_ponto()
{
    ponto *p = (ponto *)malloc(sizeof(ponto));

    if (!p)
    {
        printf("Nao deu pra alocar\n");
        exit (333);
    }
    return p;
}

void imprime(ponto *p)
{
    printf("O ponto fornecido foi: (%.2f, %.2f)\n", p->x, p->y);
}

void ler_ponto(ponto *p)
{
    printf("Digite os valores do ponto (X, Y)\n");
    scanf("%f %f", &p->x, &p->y);
}

float distancia(ponto *p1, ponto *p2)
{
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}