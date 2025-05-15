#include <stdio.h>

void minusculo(char *str);

int main(void)
{
    char str[20];

    printf("Digite um nome ai\n");
    scanf(" %s", str);

    minusculo(str);

    printf("String resultante\n");
    printf("%s\n", str);
}

void minusculo(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}