#include <stdio.h>

void string_oposta(char *str);

int main(void)
{
    char palavra1[] = "Casa!";
    string_oposta(palavra1);
    printf("String oposta: %s\n", palavra1); // Exemplo: Xzhs!
}

void string_oposta(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if (c >= 'a' && c <= 'z')
        {
            str[i] = 'z' - (c - 'a');
        }
        else if (c >= 'A' && c <= 'Z')
        {
            str[i] = 'Z' - (c - 'A');
        }
    }
}
