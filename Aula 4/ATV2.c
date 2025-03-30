#include <stdio.h>
int main()
{
    char opcao = 'i';
    do
    {
        printf("Voce gostaria de prosseguir com a execucao? (S/N) ");
        scanf("%c", &opcao);
        fflush(stdin);
    } while ((opcao != 's' && opcao != 'S') && (opcao != 'n' && opcao != 'N'));
    printf("O usuario decidiu ");
    switch (opcao)
    {
    case 's':
    case 'S':
        printf("Proseguir...");
        break;

    case 'n':
    case 'N':
        printf("Encerrar...");
        break;

    default:
        printf("Impossivel, nao entendi");
        break;
    }
    return 0;
}