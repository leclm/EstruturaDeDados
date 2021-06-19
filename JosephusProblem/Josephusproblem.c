#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <locale.h>

typedef struct soldado Soldado;

struct soldado {
	char nome[20];
	int num;
	Soldado *prox;
};

Soldado *cria_soldado(char *nome, int numero);
Soldado *remove_soldado(Soldado *lista, Soldado *soldado);
Soldado *inicializa();
int verificaCircVazio(Soldado *lista);
Soldado *insereSoldadoNoCirc(Soldado *lista, char *nome, int num);
void imprimeSoldadosCirc(Soldado *lista);
int encontraIndiceSoldado(Soldado *lista, char nome[]);
int verificaQteSoldados(Soldado *lista);
Soldado *executaJosephus(Soldado *lista, int quantidade, int numero_de_saltos, Soldado *inicial);

int main(void) {
	srand(time(0));

	int i, numero_de_saltos;
	char soldado_inicial[20];
	Soldado *listax = inicializa();

	char nomes[1];

	while (1) {
		printf("Digite o nome do soldado: ");
		scanf("%s", nomes);
		if (nomes[0] == ':') {
			break;
		}
		listax = insereSoldadoNoCirc(listax, nomes, (i + 1));
	}

	printf("Digite o numero de saltos: ");
	scanf("%d", &numero_de_saltos);

	printf("Digite o soldado inicial: ");
	scanf("%s", soldado_inicial);

	int quantidade = verificaQteSoldados(listax);
	printf("\nQuantidade de soldados: %d\n", quantidade);

	int primeiro_soldado = encontraIndiceSoldado(listax, soldado_inicial);
	if (primeiro_soldado == -1) {
		return EXIT_FAILURE;
	}

	Soldado *inicial = listax;
	for (i = 0; i < primeiro_soldado; i++)
		inicial = inicial->prox;
	listax = executaJosephus(listax, quantidade, numero_de_saltos, inicial);

	return EXIT_SUCCESS;
}

// allocate memory for a soldier pointer for him
Soldado *cria_soldado(char *nome, int numero) {
	// allocate a soldier's size memory
	Soldado *soldado = (Soldado *)malloc(sizeof(Soldado));

	// assing data to the soldier: name, index ec
	soldado->num = numero;
	strcpy(soldado->nome, nome);
	soldado->prox = soldado;

	return soldado;
}

// remove a soldier from the list
Soldado *remove_soldado(Soldado *lista, Soldado *soldado) {
	Soldado *aux = lista;

	// check if list has just one soldier
	if (soldado == aux && soldado->prox == aux) {
		lista = inicializa();

		// check if soldier is the first one
	} else if (soldado == aux) {
		lista = soldado->prox;
		do {
			aux = aux->prox;
		} while (aux->prox->prox != lista);
		aux->prox = lista;

		// if the soldier is in any other position of the list
	} else {
		do {
			if (aux->prox == soldado) {
				aux->prox = soldado->prox;
				break;
			}
			aux = aux->prox;
		} while (aux->prox != lista);
	}

	// free this soldier memory
	free(soldado);

	// return the new list, without the soldier who's goes out
	return lista;
}

// Josephus function
Soldado *executaJosephus(Soldado *lista, int quantidade, int numero_de_saltos, Soldado *inicial) {
  int i, num_iteracoes;

	// check if the circle is empty
	if (verificaCircVazio(lista)) {
		printf("\nNao ha nenhum soldado no circulo!\n");
		return lista;
	}

	// check if there is just one soldier at the circle
	if (quantidade == 1)	{
		printf("\nSoldado que vai buscar ajuda no cavalo: %s\n", lista->nome);
		return lista;
	}

	num_iteracoes = numero_de_saltos;

	printf("Quantidade de soldados restante no circulo: %d\n\n", quantidade);

	imprimeSoldadosCirc(lista);

	Soldado *aux = inicial;

	printf("Soldado que comeca a rodada: %s\n", aux->nome);

	// go through the list for N times then remove the chosen soldier
	for (i = 0; i < num_iteracoes; i++)
		aux = aux->prox;

	printf("Soldado eliminado: %s\n", aux->nome);
	Soldado *proximo = aux->prox;
	lista = remove_soldado(lista, aux);

	printf("\n-----------------------------------------\n");

	return executaJosephus(lista, quantidade - 1, numero_de_saltos, proximo);
}

// insert a soldier in the circle
Soldado *insereSoldadoNoCirc(Soldado *lista, char *nome, int num) {

	// allocate the soldier in memory
	Soldado *soldado = cria_soldado(nome, num);

	/* if list isn't empty, 
	 * go through the list until find the last element
	 * made the connection between the last soldier 'prox' attribute with the new soldier
	 * made the connection between the new soldier 'prox' attribute with the list
	 */
	if (!verificaCircVazio(lista)) {
		Soldado *aux = lista;

		while (aux->prox != lista)
			aux = aux->prox;

		aux->prox = soldado;	 // made the connection between the last element of the list and the new register
		soldado->prox = lista; // close the circular linked list by conneting the new register to the list
	}

	return soldado;
}

// print the soldier list
void imprimeSoldadosCirc(Soldado *lista) {

	Soldado *aux = lista;

	if (!verificaCircVazio(lista)) {
		do {
			printf("%s\n", aux->nome, aux, aux->prox);
			aux = aux->prox;
    } while (aux != lista);
	}
}

int encontraIndiceSoldado(Soldado *lista, char nome[]) {
	Soldado *aux = lista;

	int indice = 0;
	if (!verificaCircVazio(lista)) {
		do {
			int cmp = strcmp(aux->nome, nome);
			if (cmp == 0)
			{
				return indice;
			}
			indice++;
			aux = aux->prox;
		} while (aux != lista);
	}
	return -1;
}

// initialize list
Soldado *inicializa() {
	return NULL;
}

// check if list is empty
int verificaCircVazio(Soldado *lista) {
	return !lista;
}

// check how many soldiers there are in the list
int verificaQteSoldados(Soldado *lista) {
	int qtd = 0;
	Soldado *aux = lista;

	if (!verificaCircVazio(lista)) {
		qtd++;
		while (aux->prox != lista) {
			qtd++;
			aux = aux->prox;
		}
	}
	return qtd;
}
