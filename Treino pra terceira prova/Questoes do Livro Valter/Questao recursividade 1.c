#include <stdio.h>

typedef char *string;

void imprime_rec(string s);

int comprimento_rec(string s);

void copia_rec(string destino, string origem);

int main()
{
    char nome[51] = "Zaion";
    char nome_copia[51] = "";

    imprime_rec(nome);

    printf("\nO nome \"%s\" tem comprimento de %d caracteres.", nome, comprimento_rec(nome));

    copia_rec(nome_copia, nome);

    printf("\n\"%s\" foi copiado de \"%s\"...", nome, nome_copia);

    return 0;
}

void imprime_rec(string s)
{
    if (s[0] != '\0')
    {
        putchar(s[0]);
        imprime_rec(&s[1]);
    }
}

int comprimento_rec(string s)
{
    if (s[0] == '\0')
        return 0;
    else
        return 1 + comprimento_rec(&s[1]);
}

void copia_rec(string destino, string origem)
{

    if (origem[0] == '\0')
        destino[0] = origem[0];
    else
    {
        destino[0] = origem[0];
        copia_rec(&destino[1], &origem[1]);
    }
}