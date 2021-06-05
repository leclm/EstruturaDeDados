#include "listaSequencial.h"
#include "listaSequencial.c"
#include <stdlib.h>
#include <stdio.h>

// um ponteiro li do tipo Lista
Lista *li;

int main()
{
	int opc, x, y;
	struct ED_LE dados_edle;

	while (opc != 12)
	{
		printf("\n=-=-=-=-= MENU =-=-=-=-=\n");	
		printf("1)  Criar a lista estatica\n");
		printf("2)  Liberar  lista estatica\n");
		printf("3)  Inserir no inicio\n");
		printf("4)  Inserir no fim\n");
		printf("5)  Inserir no meio (ordenado)\n");
		printf("6)  Remover do inicio\n");
		printf("7)  Remover do fim\n");
		printf("8)  Remover do meio\n");
		printf("9)  Consultar pelo conteudo\n");
		printf("10) Consultar pela posicao\n");
		printf("11) Imprimir Lista Estatica\n");
		printf("12) Sair\n");

		printf("\nEscolha uma das opcoes acima: ");
		scanf("%d", &opc);
		switch (opc)
		{
		case 1:
			li = cria_lista();
			if (li == NULL)
			{
				printf("Ocorreu um erro ao criar a lista!\n");
			}
			else
			{
				printf("Lista criada com sucesso!\n");
			}
			break;

		case 2:
			libera_lista(li);
			printf("Lista liberada com sucesso!\n");
			break;

		case 3:
			printf("Digite o valor a ser inserido: ");
			scanf("%d", &dados_edle.valores);
			x = insere_lista_inicio(li, dados_edle);
			if (x == 1) {
				printf("Valor inserido na lista!\n");
			} else {
				printf("Ocorreu um erro ao inserir o valor na lista!\n");
			}
			break;

		case 4:
			printf("Digite o valor a ser inserido: ");
			scanf("%d", &dados_edle.valores);
			x = insere_lista_final(li, dados_edle);
			if (x == 1) {
				printf("Valor inserido na lista!\n");
			} else {
				printf("Ocorreu um erro ao inserir o valor na lista!\n");
			}
			break;

		case 5:
			printf("Digite o valor a ser inserido: ");
			scanf("%d", &dados_edle.valores);
			x = insere_lista_ordenada(li, dados_edle);
			if (x == 1) {
				printf("Valor inserido na lista!\n");
			} else {
				printf("Ocorreu um erro ao inserir o valor na lista!\n");
			}
			break;

		case 6:
			x = remove_lista_inicio(li);
			if (x == 1) {
				printf("Valor removido da lista!\n");
			} else {
				printf("Ocorreu um erro ao remover o valor da lista!\n");
			}
			break;

		case 7:
			x = remove_lista_final(li);
			if (x == 1) {
				printf("Valor removido da lista!\n");
			} else {
				printf("Ocorreu um erro ao remover o valor da lista!\n");
			}
			break;

		case 8:
			printf("Digite o valor a ser removido: ");
			scanf("%d", &dados_edle.valores);
			x = remove_lista_ordenada(li, dados_edle.valores);
			if (x == 1) {
				printf("Valor removido da lista!\n");
			} else {
				printf("Ocorreu um erro ao remover o valor da lista!\n");
			}
			break;

		case 9:
			printf("Digite o valor a ser consultado: ");
			scanf("%d", &dados_edle.valores);
			x = consulta_lista_value(li, dados_edle.valores, &dados_edle);
			if (x == 1) {
				printf("Valor encontrado na lista!\n");
			} else {
				printf("Valor nao encontrado na lista!\n");
			}
			break;

		case 10:
			printf("Digite a posicao a ser consultada: ");
			scanf("%d", &x);

			y = consulta_lista_pos(li, x, &dados_edle);

			if (y == 1) {
				printf("Valor desta posicao: %d\n", dados_edle);
			} else {
				printf("Posicao invalida!\n");
			}
			break;
		
		case 11:
			if (li->qtd == 0 || li == NULL) {
				printf("A lista esta vazia!\n");	
			} else {
				printf("Valores da Lista:\n");
				imprimir_lista(li);
			}
			break;

		case 12:
			printf("Programa encerrado!\n");
			break;

		default:
			printf("Opcao inexistente, escolha uma opcao valida!\n");
			break;
		}
	}

	return 1;
}
