#include <stdlib.h>
#include <stdio.h>

#define MAX_VETOR 5

// Definição da Estrutura Lista Linear Sequencial Estática
typedef struct Vetor {
  int dados[MAX_VETOR];
  int inicio, fim;
} Tipo_Lista;

//Operação de Inserção no Final da Lista
int insere_fim_lista(Tipo_Lista *v, int dado) {
  if ( v -> fim < MAX_VETOR ) {
    v -> dados[ v -> fim ] = dado;
    ( v -> fim)++;
    printf("\nElemento inserido!");
    return 1;
  }
  printf("\nLista cheia!");
  return 0;

}

int exclui_fim_lista( Tipo_Lista *v ) {
  v -> dados[ v -> fim - 1 ] = 0;
  ( v -> fim)--;
  printf("\nexcluiu do fim");
  return 1;
}


int exclui_inicio_lista(Tipo_Lista *v) {
  for (int i = 0; i < v -> fim - 1; i++) {
    v -> dados[i] = v -> dados[i + 1];
  }
  v -> dados[ v -> fim - 1 ] = 0;
  (v -> fim)--;
  printf("\nexcluiu do início");
  return 1;
}

//Operação de Exclusão de um Determinado Elemento da Lista
int exclui_elem_lista(Tipo_Lista *v, int indice) {
  int i, dado;
  if ( v -> fim != 0 ) {//verifica se a lista está vazia
    if (( indice >= 0 ) && ( indice < v -> fim )) { //verifica se o indice está correto  
      if ( indice == 0 ) {//verifica se exclui o primeiro elemento
        if ( exclui_inicio_lista(v) == 1 ) {
          printf("\nO elemento excluido da posicao %d", indice);
          return 1;
        }
      } else { 
        if ( indice == v -> fim - 1 ) {//verifica se exclui o ultimo elemento
          if ( exclui_fim_lista(v) == 1 ) {
            printf("\nO elemento excluido da posicao %d", indice);
            return 1;
          }
        } else {
          dado = v -> dados[indice];
          for ( i = indice; i < v -> fim; i++ ) {
            v -> dados[i] = v -> dados[i+1];
            (v -> fim)--;
            printf("\nO elemento excluido da posicao %d foi: %d", indice, dado);
            return 1;
          }
        }
      }
    }
    return -1;
  }
  return 0;
}

//Operação que Busca um Elemento na Lista
int busca_lista(Tipo_Lista v, int dado, int *indice) {
  int i, achou = 0;
  for( i = 0; i < v.fim - 1; i++ ) {
    if( v.dados[i] == dado ) {
      *indice = i;
      achou = 1;
      break;
    }
  }
  if( achou )
    return 1;
  return 0;
}

//Operação que Imprime os Elementos da Lista
int imprime_lista(Tipo_Lista V) {
  int i;
  printf("\n\n\n");
  if(V.fim != 0) {
    for(i=0; i < V.fim; i++)
      printf("\n%d", V.dados[i]);
      return 1;
    }
  return 0;
}
