#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

Lista *lst_cria();
Lista *lst_insere(Lista *lista, int valor);
Lista *lst_insere_ordenado(Lista *lista, int valor);
Lista *lst_retira(Lista *lista, int valor);
void lst_imprime(Lista *lista);
int lst_vazia(Lista *lista);
void lst_libera(Lista *lista);
Lista *lst_busca(Lista *lista, int valor);
Lista *lst_busca_ordenada(Lista *lista, int valor);
int lst_igual(Lista *l1, Lista *l2);
int lst_comprimento(Lista *lista);
int lst_maiores(Lista *lista, int n);
Lista *lst_ultimo(Lista *lista);
Lista *lst_concatena(Lista *l1, Lista *l2);
Lista *lst_separa(Lista *l, int n);

int main(void)
{
}

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

int lst_igual(Lista *l1, Lista *l2)
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

int lst_comprimento(Lista *lista)
{
    int cont = 0;

    while (lista != NULL)
    {
        cont++;
        lista = lista->prox;
    }

    return cont;
}

int lst_maiores(Lista *lista, int n)
{
    int maiores = 0;

    while (lista != NULL)
    {
        if (lista->info > n)
            maiores++;
        lista = lista->prox;
    }

    return maiores;
}

Lista *lst_ultimo(Lista *lista)
{
    Lista *anterior = NULL;

    while (lista != NULL)
    {
        anterior = lista;
        lista = lista->prox;
    }

    return anterior;
}

Lista *lst_concatena(Lista *l1, Lista *l2)
{
    if (l1 == NULL)
        return l2;

    Lista *ultimo = lst_ultimo(l1);
    ultimo->prox = l2;

    return l1;
}

Lista *lst_separa(Lista *l, int n)
{
    Lista *p = l;

    // Percorre até encontrar o nó com valor n ou fim da lista
    while (p != NULL && p->info != n)
    {
        p = p->prox;
    }

    // Se não encontrou o valor n, retorna NULL (não há segunda lista)
    if (p == NULL)
        return NULL;

    // Guarda o início da segunda lista
    Lista *nova_lista = p->prox;

    // "Desconecta" a primeira lista da segunda
    p->prox = NULL;

    // Retorna a segunda lista
    return nova_lista;
}
