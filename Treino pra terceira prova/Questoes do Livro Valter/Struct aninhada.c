#include <stdio.h>
#include <math.h>

typedef struct ponto
{
    float x;
    float y;
} Ponto;

typedef struct circulo
{
    Ponto centro;
    float raio;
} Circulo;

float distancia(Ponto *p1, Ponto *p2);
int interior(Circulo *c, Ponto *p);

int main()
{
    Ponto p;

    p.x = 1.0;
    p.y = 2.3;

    Circulo cir;

    cir.centro.x = 1.0;
    cir.centro.y = 1.5;
    cir.raio = 10;

    printf("O ponto p(%.2f, %.2f) é ", p.x, p.y);
    if (interior(&cir, &p))
        printf("interior");
    else
        printf("exterior");
    printf(" ao círculo centro(%.2f, %.2f) e raio %.2f.", cir.centro.x, cir.centro.y, cir.raio);

    return 0;
}

float distancia(Ponto *p1, Ponto *p2)
{
    return sqrt(pow(p1->x - p2->x, 2) + pow(p2->y - p1->y, 2));
}

int interior(Circulo *c, Ponto *p)
{

    return distancia(&c->centro, p) < c->raio;
}