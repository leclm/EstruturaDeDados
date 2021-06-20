#include "listaDinEncadDesc.h"
#include <stdlib.h>
#include <stdio.h>

struct elemento {
    struct ed_lde dados;
    struct elemento *proximo;
};

typedef struct elemento Elem;

// implementacao da struct descritor do arquivo .h
struct descritor {
    struct elemento *inicial;
    struct elemento *final;
    int qtd;
};

Lista *cria_lista() {
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL) {
        li->inicial = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista *li) {
    if (li != NULL) {
        Elem *no;
        while (li->inicial != NULL) {
            no = li->inicial;
            li->inicial = li->inicial->proximo;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li) {
    if (li == NULL) {
        return 0;
    } 
    return li->qtd;
}

int lista_cheia(Lista *li) {
    return 0;
    // nao faz sentido perguntar se uma lista dinamica esta cheia, pois ela só estará cheia quando acabar a memoria do computador. return false
}

int lista_vazia(Lista *li)
{
    if (li == NULL) {
        return 1; // se a lista for nula/se ela estiver vazia, true
    }
    if (li->inicial == NULL) {
        return 1; // se o ponteiro for null, ou seja, o inicio da lista aponta para null, a lista esta vazia, true
    }
    return 0; // se nao executei nenhum dos dois if acima, retorno 0 (false), ou seja, a lista nao esta vazia. O return encerra a funcao, se um dos if for executado, nao vai chegar a executar essa linha.
}

int insere_lista_inicio(Lista *li, struct ed_lde edlde) {
    if (li == NULL) {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL) {
        return 0; // se o no for null significa que nao consegui alocar memoria para o novo nó, return false
    }

    no->dados = edlde; // copio os dados que eu quero inserir na lista pra dentro do no, esse dado foi passado por parametro em edlde na chamada da funcao
    no->proximo = li->inicial;
    if(li->inicial == NULL) {
        li->final = no;
    }
    li->inicial = no;
    li->qtd++;

    return 1;
}

int insere_lista_final(Lista *li, struct ed_lde edlde) {
    if (li == NULL) {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL) {
        return 0;
    }

    no->dados = edlde;
    no->proximo = NULL;

    if (li->inicial == NULL) {
        li->inicial = no; // lista vazia, insere no inicio
    }
    else {
       li->final->proximo = no;
    }

    li->final = no;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista *li, struct ed_lde edlde) {
    if (li == NULL) {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL) {
        return 0;
    }

    no->dados = edlde;
    no->proximo = NULL;
    if (li->inicial == NULL) { // insere no inicio
        li->inicial = no;
        li->qtd++;
        return 1;
    } else {
        Elem *ant, *atual = li->inicial;
        while (atual != NULL && atual->dados.valor < edlde.valor) {
            ant = atual;
            atual = atual->proximo;
        }
        if (atual == li->inicial) { //insere inicio
            no->proximo = li->inicial;
            li->inicial = no;
        } else {
            no->proximo = ant->proximo;
            ant->proximo = no;
        }
        li->qtd++;
        return 1;
    }
}

int remove_lista_inicio(Lista *li) {
    if (li == NULL) {
        return 0;
    }
    if (li->inicial == NULL) { // lista vazia
        return 0;
    }

    // criacao de um novo elemento nó, que vai receber o valor do elemento no inicio da lista
    Elem *no = li->inicial;
    // inicio da lista passa a apontar pro elemento seguinte ao no
    li->inicial = no->proximo;
    // removemos o nó
    free(no);

    if (li->inicial == NULL) {
        li->final = NULL;
    }

    li->qtd--;

    return 1;
}

int remove_lista_final(Lista *li) {
    if (li == NULL) {
        return 0;
    }
    if (li->inicial == NULL) { // lista vazia
        return 0;
    }

    Elem *ant, *no = li->inicial;

    while (no->proximo != NULL) {
        ant = no;
        no = no->proximo;
    }

    if (no == li->inicial) { // só tem um elemento na lista
        li->inicial = NULL;
        li->final = NULL;
    } else {
        ant->proximo = no->proximo;
        li->final = ant->proximo;
    }
    free(no);
    li->qtd--;
    return 1;
}

int remove_lista_ordenada(Lista *li, int value) {
    if (li == NULL) {
        return 0;
    }

    Elem *ant, *no = li->inicial;

    while (no != NULL && no->dados.valor != value) {
        ant = no;
        no = no->proximo;
    }

    if (no == NULL) { // nao encontrado
        return 0;
    }

    if (no == li->inicial) { // só tem um elemento na lista, remove o primeiro
        li->inicial = NULL;
        li->final = NULL;
    } else {
        ant->proximo = no->proximo;
        li->final = ant->proximo;
    }

    free(no);
    li->qtd--;
    return 1;
}

int consulta_lista_value(Lista *li, int value, struct ed_lde *edlde) {
    if (li == NULL) {
        return 0;
    }

    Elem *no = li->inicial;
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

int consulta_lista_pos(Lista *li, int pos, struct ed_lde *edlde) {
    if (li == NULL || pos <= 0) {
        return 0;
    }

    Elem *no = li->inicial;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->proximo;
        i++;
    }
    if (no == NULL) {
        return 0;
    }
    else {
        *edlde = no->dados;
        return 1;
    }
}

int imprimir_lista(Lista *li, struct ed_lde *edlde) {
    Elem *no = li->inicial;

    for (int i = 0; i < li->qtd; i++) {
        printf("%d ", no->dados);
        no = no->proximo;
    }
    printf("\n");
    return 1;
}
