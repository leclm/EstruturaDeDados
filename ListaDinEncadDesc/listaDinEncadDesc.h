struct ed_lde {
	int valor;
};

typedef struct descritor Lista;

// equivalente a fopen() em arquivos, essa funcao eh que vai inicializar a minha lista
Lista* cria_lista();

//equivalente ao fclose() em arquivos
void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_vazia(Lista* li);

int lista_cheia(Lista* li);

int insere_lista_inicio(Lista* li, struct ed_lde edlde);

int insere_lista_final(Lista* li, struct ed_lde edlde);

int insere_lista_ordenada(Lista* li, struct ed_lde edlde);

int remove_lista_inicio(Lista* li);

int remove_lista_final(Lista* li);

int remove_lista_ordenada(Lista* li, int value);

int consulta_lista_value(Lista* li, int value, struct ed_lde *edlne);

int consulta_lista_pos(Lista* li, int pos, struct ed_lde *edlde); // passa um ponteiro para a struct ed_lde, que é onde eu vou guardar as informações, estamos trabalhando com o acesso por referência, passagem de parâmetro por referência. Então eu passo um ponteiro para a estrutura de modo que essa estrutura possa ser preenchida dentro da função com os dados que eu quero

int imprimir_lista(Lista* li, struct ed_lde *edlde);