#include <stdio.h>
#include <math.h>

typedef struct ponto
{
    float x;
    float y;
} Ponto;

Ponto centro_geometrico(int n, Ponto *v);

int main()
{
    Ponto triangulo[3] = {{0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0}};

    Ponto centro_geo = centro_geometrico(3, triangulo);

    printf("\nO centro geométrico do triângulo é...\n");
    printf("C (%.2f, %.2f)\n", centro_geo.x, centro_geo.y);

    return 0;
}

// Calcula o centro geométrico de um conjunto de n pontos.
Ponto centro_geometrico(int n, Ponto *v)
{
    Ponto p = {0.0, 0.0};

    for (int i = 0; i < n; i++)
    {
        p.x += v[i].x;
        p.y += v[i].y;
    }

    p.x /= n;
    p.y /= n;

    return p;
}