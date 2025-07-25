#include <stdio.h>

int conta_vogais(char* string);

int main(){
    char* nome_estado = "Ceará";

    printf("\nA string %s contém %d vogais.\n", nome_estado, conta_vogais(nome_estado));

    return 0;
}

int conta_vogais(char* string){
    char vogais[] = {'a', 'á', 'â', 'ã' ,'e', 'é','i', 'í', 'o', 'ó', 'u', 'ú', 'A', 'Á', 'E', 'É', 'I', 'Í', 'O', 'Ó', 'U', 'Ú', '\0'}; 
    int conta_vogal = 0;

    for(int i = 0; string[i] != '\0'; i++)
        for(int j = 0; vogais[j] != '\0'; j++)
            if(string[i]  == vogais[j]){
                conta_vogal++;
                break;
            }

    return conta_vogal;
    
}