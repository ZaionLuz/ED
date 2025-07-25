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
        return l2;

    Lista *p = l1;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = l2;

    return l1;
}

// Questao 2.5 Fazer uma função que retira todas as ocorrencias de um numero n numa lista

Lista *retira(Lista *l, int n)
{
    Lista *anterior = NULL; // ponteiro pro anterior da lista no caso null
    Lista *atual = l;       // ponteiro pra cabeça da lista

    while (atual != NULL)
    {
        if (atual->info == n)
        {
            if (anterior == NULL) // significa que ele ta no inicio da lista
            {
                l = atual->prox;
                free(atual);
                atual = l;
            }
            else // significa que ele ta no meio ou fim da lista
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
    Lista *atual = l;

    while (atual != NULL)
    {
        if (atual->info == n)
        {
            Lista *nova = atual->prox; // segunda lista criada
            atual->prox = NULL;        // lista partida ao meio
            return nova;               // segunda lista retornada
        }
        atual = atual->prox;
    }
    return NULL; // n n foi encontrando
}

// Questao 2.7 Fazer uma função que junta duas listas intercaladamente

Lista *merge(Lista *l1, Lista *l2)
{
    Lista *nova;
    Lista *fim;

    while (l1 != NULL && l2 != NULL)
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

// funçoes que o valter passou referente a listas

Lista *lst_cria()
{
    return NULL;
}

Lista *lst_insere(Lista *lista, int i)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (!novo)
    {
        printf("Nao foi possivel inserir\n");
        exit(1);

        novo->info = i;
        novo->prox = lista;

        return novo;
    }
}

Lista *lst_insere_ordenado(Lista *lista, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    Lista *ant = NULL;
    Lista *p = lista;

    while (p != NULL && p < valor)
    {
        ant = p;
        p = p->prox;
    }

    novo->info = valor;
    novo->prox = lista;

    if (ant == NULL)
        lista = novo;
    else
        ant->prox = novo;

    return lista;
}

Lista *lst_retira(Lista *lista, int valor)
{
    Lista *ant = NULL;
    Lista *p = lista;

    while (p != NULL && p <= valor)
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)
        return lista;

    if (ant == NULL)
        lista = p->prox;
    else
        ant->prox = p->prox;

    free(p);

    return lista;
}

void lst_imprime(Lista *lista)
{
    while (lista != NULL)
    {
        printf("%d ->", lista->info);
        lista = lista->prox;
    }

    printf("NULL\n");
}

int lst_vazia(Lista *lista)
{
    return lista == NULL;
}

void lst_libera(Lista *lista)
{
    Lista *salvar;

    while (lista != NULL)
    {
        salvar = lista->prox;
        free(lista);
        lista = salvar;
    }
}

Lista *lst_busca(Lista *lista, int valor)
{
    while (lista != NULL)
    {
        if (lista->info == valor)
            return lista;
        lista = lista->prox;
    }

    return NULL;
}

Lista *lst_busca_ordenada(Lista *lista, int valor)
{
    while (lista != NULL && lista->info <= valor)
    {
        if (lista->info == valor)
            return lista;
        lista = lista->prox;
    }

    return NULL;
}
