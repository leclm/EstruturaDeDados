#pragma once
/* Prototipo das funcoes
  tipo de dado armazenado na lista
  o ponteiro "lista"
  tamanho do vetor usado na lista
*/

#define MAX 5

struct ED_LE {
	int valores;
};

//crio um apelido para a "struct lista", para nao precisar escrever "struct lista" toda vez, agora posso chamar apenas de "Lista"
typedef struct lista Lista;

// equivalente a fopen() em arquivos, essa funcao eh que vai inicializar a minha lista
Lista* cria_lista();

// equivalente ao fclose() em arquivos
void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

int insere_lista_final(Lista* li, struct ED_LE edle);

int insere_lista_inicio(Lista* li, struct ED_LE edle);

int insere_lista_ordenada(Lista* li, struct ED_LE edle);

int remove_lista_final(Lista* li);

int remove_lista_inicio(Lista* li);

int remove_lista_ordenada(Lista* li, int value);

int consulta_lista_pos(Lista* li, int pos, struct ED_LE *edle); // passa um ponteiro para a struct ED_LE, que é onde eu vou guardar as informações, estamos trabalhando com o acesso por referência, passagem de parâmetro por referência. Então eu passo um ponteiro para estrutura de modo que essa estrutura possa ser preenchida dentro da função com os dados que eu quero

int consulta_lista_value(Lista* li, int value, struct ED_LE *edle);

int imprimir_lista(Lista* li);