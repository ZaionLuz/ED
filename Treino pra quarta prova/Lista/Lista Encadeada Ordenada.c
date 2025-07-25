#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

Lista *lst_cria();
Lista *lst_insere_ordenado(Lista *l, int v);
Lista *lst_retira(Lista *l, int v);
void lst_imprime(Lista *l);
int lst_vazia(Lista *l);
void lst_libera(Lista *l);
Lista *lst_busca_ordenada(Lista *l, int v);
int lst_igual(Lista *l1, Lista *l2);

int main()
{

    Lista *minha_lista1 = lst_cria();
    Lista *minha_lista2 = lst_cria();

    for (int i = 0; i < 50; i++)
    {
        minha_lista1 = lst_insere_ordenado(minha_lista1, i + 1);
        minha_lista2 = lst_insere_ordenado(minha_lista2, i + 1);
    }

    lst_imprime(minha_lista1);

    printf("# Buscando na lista #\n");
    printf("Digite o valor a ser buscado: ");
    int valor_busca = 0;
    scanf("%d", &valor_busca);

    printf("Elemento ");

    if (lst_busca_ordenada(minha_lista1, valor_busca))
    {
        printf("encontrado...\n");
        printf("Voce quer deleta-lo? S/N...");
        char opcao;
        scanf(" %c%*c", &opcao);

        switch (opcao)
        {
        case 's':
        case 'S':
            minha_lista1 = lst_retira(minha_lista1, valor_busca);
            lst_imprime(minha_lista1);
            break;
        }
    }
    else
        printf("nao encontrado...\n");

    printf("As listas 1 e 2 sao ");
    if (lst_igual(minha_lista1, minha_lista2))
        printf("iguais...\n");
    else
        printf("diferentes...\n");

    lst_libera(minha_lista1);
    lst_libera(minha_lista2);

    return 0;
}

Lista *lst_cria()
{
    return NULL;
}

void lst_imprime(Lista *l)
{
    Lista *p;

    for (p = l; p != NULL; p = p->prox)
        printf("info: %d\n", p->info);
}

int lst_vazia(Lista *l)
{
    return l == NULL;
}

void lst_libera(Lista *l)
{
    Lista *p = l;

    while (p != NULL)
    {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

Lista *lst_busca_ordenada(Lista *l, int v)
{

    for (Lista *p = l; p != NULL && p->info <= v; p = p->prox)
        if (p->info == v)
            return p;

    return NULL;
}

Lista *lst_retira(Lista *l, int v)
{
    Lista *ant = NULL;
    Lista *p = l;

    while (p != NULL && p->info != v)
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL)
        return l;

    if (ant == NULL)
        l = p->prox;
    else
        ant->prox = p->prox;

    free(p);

    return l;
}

Lista *lst_insere_ordenado(Lista *l, int v)
{
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = l;

    while (p != NULL && p->info < v)
    {
        ant = p;
        p = p->prox;
    }

    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = v;

    if (ant == NULL)
    {
        novo->prox = l;
        l = novo;
    }
    else
    {
        novo->prox = p;
        ant->prox = novo;
    }

    return l;
}

int lst_igual(Lista *l1, Lista *l2)
{

    Lista *p1;
    Lista *p2;

    for (p1 = l1, p2 = l2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox)
        if (p1->info != p2->info)
            return 0;

    return p1 == p2;
}