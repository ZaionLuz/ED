#include <stdio.h>
#include <string.h>

void roda_string(char *str);

int main(void)
{
    char palavra2[] = "casa";
    roda_string(palavra2);
    printf("String rodada: %s\n", palavra2); // Saída: acas
}

void roda_string(char *str)
{
    int len = strlen(str);

    if (len <= 1)
        return;

    char ultimo = str[len - 1];

    for (int i = len - 1; i > 0; i--)
    {
        str[i] = str[i - 1];
    }

    str[0] = ultimo;
}