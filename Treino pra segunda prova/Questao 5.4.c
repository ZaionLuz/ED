#include <stdio.h>

void shift_string(char *str);

int main(void)
{
    char str[20];

    printf("Digite um nome\n");
    scanf(" %s", str);

    shift_string(str);
    printf("Nome alterado:\n");
    printf("%s", str);
}

void shift_string(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        // Minúsculas
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (str[i] == 'z')
                str[i] = 'a';
            else
                str[i]++;
        }
        // Maiúsculas
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (str[i] == 'Z')
                str[i] = 'A';
            else
                str[i]++;
        }
    }
}
