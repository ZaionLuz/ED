#include <stdio.h>
#include <math.h>

double avalia(double *poli, int grau, double x);

int main()
{
    // Polinômio: 3x² + 2x + 12
    double poli[] = {12, 2, 3};
    int grau = 2;
    double x = 2; // ponto onde queremos avaliar o polinômio

    double resultado = avalia(poli, grau, x);
    printf("Resultado da avaliacao do polinomio em x = %.2f: %.2f\n", x, resultado);

    return 0;
}

double avalia(double *poli, int grau, double x)
{
    double resultado = 0;
    for (int i = 0; i <= grau; i++)
    {
        resultado += poli[i] * pow(x, i);
    }
    return resultado;
}