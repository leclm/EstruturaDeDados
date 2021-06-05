/* tipo de dados "lista"
  implementar as suas funcoes
*/
#include "listaDinEncad.h"
#include <stdlib.h>
#include <stdio.h>

// implementacao da struct elemento do arquivo .h
struct elemento
{
    struct ed_lde dados;
    struct elemento *proximo;
};

typedef struct elemento Elem;

Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
    {
        *li = NULL;
    }
    return li;
}

void libera_lista(Lista *li)
{
    if (li != NULL) {
        Elem *no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->proximo;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li)
{
    if (li == NULL) {
        return 0;
    }
    int count = 0;
    Elem *no = *li;
    while (no != NULL)
    {
        count++;
        no = no->proximo;
    }
    return count;
}

int lista_cheia(Lista *li)
{
    return 0;
    // nao faz sentido perguntar se uma lista dinamica esta cheia, pois ela só estará cheia quando acabar a memoria do computador. return false
}

int lista_vazia(Lista *li)
{
    if (li == NULL)
    {
        return 1; // se a lista for nula, se ela estiver vazia, true
    }
    if (*li == NULL)
    {
        return 1; // se o ponteiro for null, ou seja, o inicio da lista aponta para null, a lista esta vazia, true
    }
    return 0; // se nao executei nenhum dos dois if acima, retorno 0 (false), ou seja, a lista nao esta vazia. O return encerra a funcao, se um dos if for executado, nao vai chegar a executar essa linha.
}

int insere_lista_inicio(Lista *li, struct ed_lde edlde)
{
    if (li == NULL)
    {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
    {
        return 0; // se o no for null significa que nao consegui alocar memoria para o novo nó, return false
    }

    no->dados = edlde; // copio os dados que eu quero inserir na lista pra dentro do no, esse dado foi passado por parametro em edlde na chamada da funcao
    no->proximo = (*li);
    *li = no;

    return 1;
}

int insere_lista_final(Lista *li, struct ed_lde edlde)
{
    if (li == NULL)
    {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
    {
        return 0;
    }

    no->dados = edlde;
    no->proximo = NULL;

    if ((*li) == NULL)
    {
        *li = no; // lista vazia, isnere no inicio
    }
    else
    {
        Elem *aux = *li;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
    return 1;
}

int insere_lista_ordenada(Lista *li, struct ed_lde edlde)
{
    if (li == NULL)
    {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
    {
        return 0;
    }
    no->dados = edlde;

    if (lista_vazia(li))
    { // insere no inicio
        no->proximo = (*li);
        *li = no;
        return 1;
    }
    else
    {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dados.valor < edlde.valor)
        {
            ant = atual;
            atual = atual->proximo;
        }
        if (atual == *li)
        { //insere inicio
            no->proximo = (*li);
            *li = no;
        }
        else
        {
            no->proximo = ant->proximo;
            ant->proximo = no;
        }
        return 1;
    }
}

int remove_lista_inicio(Lista *li)
{
    if (li == NULL)
    {
        return 0;
    }
    if ((*li) == NULL)
    { // lista vazia
        return 0;
    }

    // criacao de um novo elemento nó, que vai receber o valor do elemento no inicio da lista
    Elem *no = *li;
    // inicio da lista passa a apontar pro elemento srguinte ao no
    *li = no->proximo;
    // removemos o nó
    free(no);
    return 1;
}

int remove_lista_final(Lista *li)
{
    if (li == NULL)
    {
        return 0;
    }
    if ((*li) == NULL)
    { // lista vazia
        return 0;
    }

    Elem *ant, *no = *li;

    while (no->proximo != NULL)
    {
        ant = no;
        no = no->proximo;
    }

    if (no == (*li))
    { // só tem um elemento na lista
        *li = no->proximo;
    }
    else
    {
        ant->proximo = no->proximo;
    }
    free(no);
    return 1;
}

int remove_lista_ordenada(Lista *li, int value)
{
    if (li == NULL)
    {
        return 0;
    }

    Elem *ant, *no = *li;

    while (no != NULL && no->dados.valor != value)
    {
        ant = no;
        no = no->proximo;
    }

    if (no == NULL)
    { // nao encontrado
        return 0;
    }

    if (no == (*li))
    { // só tem um elemento na lista, remove o primeiro
        *li = no->proximo;
    }
    else
    {
        ant->proximo = no->proximo;
    }

    free(no);
    return 1;
}

int consulta_lista_value(Lista *li, int value, struct ed_lde *edlde) {
    if (li == NULL) {
        return 0;
    }

    Elem *no = *li;
    int pos = 1;

    while (no != NULL && no->dados.valor != value) {
        no = no->proximo;
        pos++;
    }

    if (no == NULL) {
        return 0;
    } else {
        *edlde = no->dados;
        return pos;
    }
}

int consulta_lista_pos(Lista *li, int pos, struct ed_lde *edlde)
{
    if (li == NULL || pos <= 0)
    {
        return 0;
    }

    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos)
    {
        no = no->proximo;
        i++;
    }
    if (no == NULL)
    {
        return 0;
    }
    else
    {
        *edlde = no->dados;
        return 1;
    }
}

int imprimir_lista(Lista *li, struct ed_lde *edlde) {
    Elem *no = *li;

    for (int i = 0; i < tamanho_lista(li); i++) {
        printf("%d ", no->dados);
        no = no->proximo;
    }
    printf("\n");
    return 1;
}
