#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

// Questao 2.1 Fazer uma função que diz o comprimento de uma lista

int comprimento(Lista *l)
{
    int tamanho = 0;

    while (l != NULL)
    {
        tamanho++;
        l = l->prox;
    }

    return tamanho;
}

// Questao 2.2 Fazer uma função que diz quantos numeros numa lista são maiores que n

int maiores(Lista *l, int n)
{
    int cont = 0;

    while (l != NULL)
    {
        if (l->info > n)
            cont++;
        l = l->prox;
    }

    return cont;
}

// Questao 2.3 Fazer uma função que retorna o ultimo nó de uma lista

Lista *ultimo(Lista *l)
{
    if (l == NULL)
        return l;

    while (l->prox != NULL)
        l = l->prox;

    return l;
}

// Questao 2.4 Fazer uma função que concatena 2 listas (o ultimo da 1 aponta pro primeiro da segunda)

Lista *concatena(Lista *l1, Lista *l2)
{
    if (l1 == NULL)
        return l2; // Se l1 for vazia, a concatenação é só l2

    Lista *p = l1; // ponteiro para percorrer l1

    while (p->prox != NULL)
        p = p->prox;

    p->prox = l2; // o último da l1 aponta para o início da l2

    return l1; // retorna o início da lista concatenada
}

// Questao 2.5 Fazer uma função que retira todas as ocorrencias de um numero n numa lista

Lista *retira(Lista *l, int n)
{
    Lista *anterior = NULL;
    Lista *atual = l;

    while (atual != NULL)
    {
        if (atual->info == n)
        {
            if (anterior == NULL)
            {
                // Removendo o primeiro elemento
                l = atual->prox;
                free(atual);
                atual = l;
            }
            else
            {
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
            }
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }

    return l;
}

// Questao2.6 Fazer uma função que separa uma lista na primeira ocorrencia de n

Lista *separa(Lista *l, int n)
{
    Lista *anterior = NULL;
    Lista *atual = l;

    while (atual != NULL)
    {
        if (atual->info == n)
        {
            if (anterior != NULL)
            {
                anterior->prox = NULL; // corta a lista
            }
            else
            {
                // n está logo no primeiro elemento
                l = NULL;
            }
            return atual; // segunda parte da lista
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Se n não for encontrado, retorna NULL (lista não é separada)
    return NULL;
}

// Questao 2.7 Fazer uma função que junta duas listas intercaladamente

Lista *merge(Lista *l1, Lista *l2)
{
    Lista *nova = NULL;
    Lista *fim = NULL;

    while (l1 != NULL || l2 != NULL)
    {
        Lista *novo = (Lista *)malloc(sizeof(Lista));
        novo->prox = NULL;

        if (l1 != NULL)
        {
            novo->info = l1->info;
            l1 = l1->prox;
        }
        else
        {
            novo->info = l2->info;
            l2 = l2->prox;
        }

        if (nova == NULL)
        {
            nova = novo;
            fim = novo;
        }
        else
        {
            fim->prox = novo;
            fim = novo;
        }
    }

    return nova;
}

// Questao 2.8 Fazer uma função que inverte uma lista

Lista *inverte(Lista *l)
{
    Lista *anterior = NULL;
    Lista *atual = l;
    Lista *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->prox;  // guarda o próximo nó
        atual->prox = anterior; // inverte o ponteiro
        anterior = atual;       // move o anterior para o atual
        atual = proximo;        // avança para o próximo
    }

    return anterior; // novo início da lista
}

// Questao 2.9 Fazer uma função que compara 2 listas de caracteres para ver se sao iguais.

int igual(Lista *l1, Lista *l2)
{
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->info != l2->info)
            return 0;
        l1 = l1->prox;
        l2 = l2->prox;
    }

    return l1 == l2;
}

// Questao 2.10 Fazer uma função que copia uma lista de caracteres

Lista *copia(Lista *l)
{
    if (l == NULL)
        return NULL;

    Lista *nova_lista = NULL;
    Lista *ultimo = NULL;

    while (l != NULL)
    {
        // 1. Descobrir o tamanho da string manualmente
        int len = 0;
        while (l->info[len] != '\0')
        {
            len++;
        }

        // 2. Alocar espaço para a nova string (+1 para o '\0')
        char *nova_str = (char *)malloc((len + 1) * sizeof(char));
        if (nova_str == NULL)
            return NULL;

        // 3. Copiar os caracteres um a um
        for (int i = 0; i <= len; i++)
        {
            nova_str[i] = l->info[i]; // inclui o '\0'
        }

        // 4. Criar nova célula da lista
        Lista *nova_celula = (Lista *)malloc(sizeof(Lista));
        if (nova_celula == NULL)
            return NULL;

        nova_celula->info = nova_str;
        nova_celula->prox = NULL;

        // 5. Inserir na nova lista
        if (nova_lista == NULL)
        {
            nova_lista = nova_celula;
        }
        else
        {
            ultimo->prox = nova_celula;
        }

        ultimo = nova_celula;
        l = l->prox;
    }

    return nova_lista;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    char *info;
    struct lista *prox;
} Lista;

// Função para criar lista vazia
Lista *lst_cria()
{
    return NULL;
}

// Função para inserir no início da lista
Lista *lst_insere(Lista *l, char c)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = c;
    novo->prox = l;
    return novo;
}

// Função para liberar a lista
void lst_libera(Lista *l)
{
    Lista *aux;
    while (l != NULL)
    {
        aux = l->prox;
        free(l);
        l = aux;
    }
}

// Função para imprimir lista (para depuração)
void lst_imprime(Lista *l)
{
    while (l != NULL)
    {
        printf("%c -> ", l->info);
        l = l->prox;
    }
    printf("NULL\n");
}

// Função main para testar
int main()
{
    Lista *lista1 = lst_cria();
    Lista *lista2 = lst_cria();

    // Inserindo elementos: como insere no início, a ordem será invertida
    lista1 = lst_insere(lista1, 'c');
    lista1 = lst_insere(lista1, 'b');
    lista1 = lst_insere(lista1, 'a');

    lista2 = lst_insere(lista2, 'c');
    lista2 = lst_insere(lista2, 'b');
    lista2 = lst_insere(lista2, 'a');

    printf("Lista 1: ");
    lst_imprime(lista1);
    printf("Lista 2: ");
    lst_imprime(lista2);

    if (igual(lista1, lista2))
        printf("As listas são iguais.\n");
    else
        printf("As listas são diferentes.\n");

    // Testando listas diferentes
    lista2 = lst_insere(lista2, 'x'); // Agora são diferentes

    if (igual(lista1, lista2))
        printf("As listas são iguais.\n");
    else
        printf("As listas são diferentes.\n");

    // Libera memória
    lst_libera(lista1);
    lst_libera(lista2);

    return 0;
}