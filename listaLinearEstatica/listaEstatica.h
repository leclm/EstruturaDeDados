#define MAX_VETOR 5

// Definição da Estrutura Lista Linear Sequencial Estática
typedef struct Vetor {
  int dados[MAX_VETOR];
  int inicio, fim;
} Tipo_Lista;

//Operação de Inserção no Final da Lista
int insere_fim_lista(Tipo_Lista *v, int dado) {
  if ( v -> fim < MAX_VETOR ) {
    printf("ihuuuu");
    return 1;
  }
  return 0;
}