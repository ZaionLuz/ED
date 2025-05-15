#include <stdio.h>

int conta_char(char *str, char c);

int main(void)
{
    char str[20]; 
    char c;

    printf("Digite um nome qualquer\n");
    scanf(" %s", str); 

    printf("Digite um caracter pra ver se ta dentro ou nao\n");
    scanf(" %c", &c); 

    int retorno = conta_char(str, c);
    printf("O caracter '%c' aparece %d vezes\n", c, retorno);

    return 0;
}

int conta_char(char *str, char c)
{
    int conta = 0;

    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == c)
            conta++;
    }

    return conta;
}
