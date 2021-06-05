/* tipo de dados "lista"
  implementar as suas fun��es
*/
#include "listaSequencial.h"
#include <stdlib.h>
#include <stdio.h>

// implementacao da struct lista do arquivo .h
struct lista {
    int qtd; // quantas posi��es eu ja ocupei da minha lista
    struct ED_LE dados[MAX]; // vetor de tamanho MAX da estrutura ED_LE, nesse vetor chamado "dados" vai ter at� 5 valores.
};

Lista* cria_lista() {
    Lista* li;
    li = (Lista*)malloc(sizeof(struct lista));
    if (li != NULL) {
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista* li) {
    free(li);
}

int tamanho_lista(Lista* li) {
    if (li == NULL) {
        return -1;
    }
    else {
        return li->qtd; // usar a seta equivale a acessar o conteudo do ponteiro, como � uma estrutura, acessa o campo da struc. Equivalente a escrever *(li).campo_da_estrutura, nesse caso, *(li).qtd
    }
}

int lista_cheia(Lista* li) {
    if (li == NULL) {
        return -1;
    }
    return li->qtd == MAX;
    // se o return for verdade, vai retornar 1, se for false, vai retornar 0 - quantidade == 5 ou quantidade != 5
}

int lista_vazia(Lista* li) {
    if (li == NULL) {
        return -1;
    }
    return li->qtd == 0; // é um comparação: true 0 (lista vazia) false 1 (lista nao vazia)
}

int insere_lista_final(Lista* li, struct ED_LE edle) {
    if (li == NULL) {
        return 0;
    }
    if (lista_cheia(li)) {
        return 0;
    }
    li->dados[li->qtd] = edle;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct ED_LE edle) {
    if (li == NULL) {
        return 0;
    }
    if (lista_cheia(li)) {
        return 0;
    }
    for (int i = li->qtd-1; i >= 0; i--) {
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = edle;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct ED_LE edle) {
    if (li == NULL) {
        return 0;
    }
    if (lista_cheia(li)) {
        return 0;
    }
    int k, i = 0;
    while (i < li->qtd && li->dados[i].valores < edle.valores) {
        i++;
    }
    for (k = li->qtd-1; k >= i; k--) {
        li->dados[k+1] = li->dados[k];
    }
    li->dados[i] = edle;
    li->qtd++;

    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL) {
        return 0;
    }
    if (li->qtd == 0) {
        return 0;
    }
    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista* li) {
    if (li == NULL) {
        return 0;
    }
    if (li->qtd == 0) {
        return 0;
    }
    int k = 0;
    for (k = 0; k < li->qtd-1; k++) {
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int remove_lista_ordenada(Lista* li, int value) {
    if (li == NULL) {
        return 0;
    }
    if (li->qtd == 0) {
        return 0;
    }
    int k, i = 0;
    while (i < li->qtd && li->dados[i].valores != value) {
        i++;
    }
    if (i == li->qtd) {
        return 0;
    }
    for (k = i; k < li->qtd-1; k++) {
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct ED_LE *edle) {
    if (li == NULL || pos <= 0 || pos > li->qtd) {
        return 0;
    }
    *edle = li->dados[pos-1]; // modifica o conteudo da estrutura com os dados que estao em pos-1
    return 1;
}

int consulta_lista_value(Lista* li, int value, struct ED_LE *edle) {
    if (li == NULL) {
        return 0;
    }
    int i;
    while (i < li->qtd && li->dados[i].valores != value) {
        i++;
    }
    if (i == li->qtd) {
        return 0;
    }
    *edle = li->dados[i];
    return 1;
}

int imprimir_lista(Lista* li) {
    for (int i = 0; i < li->qtd; i++) {
        printf("%d ", li->dados[i].valores);
    }
    printf("\n");
}