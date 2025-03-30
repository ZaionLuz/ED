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
    if (opcao == 's' || opcao == 'S')
    {
        printf("Proseguir...");
    }
    else
    {
        if (opcao == 'n' || opcao == 'N')
        {
            printf("Encerrar...");
        }
        else
        {
            printf("Impossivel, nao entendi");
        }
    }
    return 0;
}