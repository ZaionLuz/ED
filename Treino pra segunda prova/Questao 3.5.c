#include <stdio.h>

void deriva(double *poli, int grau, double *out);

int main()
{
    // Polinômio: 3x² + 2x + 12
    double poli[] = {12, 2, 3};
    int grau = 2;
    double derivada[grau];

    deriva(poli, grau, derivada);

    printf("Derivada do polinomio: ");
    for (int i = 0; i < grau; i++)
    {
        printf("%.2f ", derivada[i]);
    }
    printf("\n");

    return 0;
}

void deriva(double *poli, int grau, double *out)
{
    for (int i = 1; i <= grau; i++)
    {
        out[i - 1] = poli[i] * i;
    }
}