#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz_Esparsa
{
	float dado;
	int li, col;
	struct Matriz_Esparsa *proximo;
} Matriz_Esparsa;

int linhas;
int colunas;

//Matriz A: Dimensões LA - CA, Ponteiro Externo A ExtA
//Matriz B: Dimensões LB - CB, Ponteiro Externo B ExtB
//Matriz Result: Dimensões LR - CR, Ponteiro Externo R ExtR

void inicializa_lista(Matriz_Esparsa **N) //inicializa a lista
{
	*N = NULL;
}

Matriz_Esparsa *Cria_Matriz_Esparsa()
{
	Matriz_Esparsa *p;
	p = (Matriz_Esparsa *)malloc(sizeof(Matriz_Esparsa));
	if (!p)
	{
		printf("Problema de alocacao");
		exit(0);
	}
	return p;
}

void insere_inicio_lista(Matriz_Esparsa **N, int dado, int li, int col)
{
	Matriz_Esparsa *novo;
	novo = Cria_Matriz_Esparsa();
	novo->dado = dado;
	novo->li = li;
	novo->col = col;
	novo->proximo = *N;
	*N = novo;
}

void busca_posi(Matriz_Esparsa **N, int linha, int coluna, float *value)
{
	int found, dado;
	found = 0;
	Matriz_Esparsa *aux;

	if (*N == NULL)
		printf("A lista esta vazia!\n");
	else
	// printf("else busca\n");
	{
		for (aux = *N; aux != NULL; aux = aux->proximo)
		{
			if (aux->li == linha && aux->col == coluna)
			{
				// printf("Valor %f Encontrado!\n Linha → %d\n Coluna → %d \n\n",aux->dado, aux->li, aux->col);
				found = 1;
				*value = aux->dado;
			}

			if (found == 0)
				*value = 0;
			return;
		}
	}
}

void insereOrdLista(Matriz_Esparsa **N, float dado, int lin, int colu)
{
	printf("Antes de alocar\n");
	Matriz_Esparsa *novo;
	Matriz_Esparsa *aux = *N;
	Matriz_Esparsa *prox;
	float value = 0;
	novo = Cria_Matriz_Esparsa();
	novo->dado = dado;
	novo->li = lin;
	novo->col = colu;
	//insere_inicio_lista(N, dado, lin, colu);
	printf("\n entrou no insere_inicio_lista \n");
	busca_posi(N, lin, colu, &value);
	if (value != 0)
	{
		printf("posicoes ja alocadas!\n");
		return;
	}

	if (*N == NULL)
	{
		*N = novo;
		printf("N = NULL \n");
	}
	else if (lin < aux->li)
	{
		printf("if linha < aux->li \n");
		novo->proximo = *N;
		*N = novo;
	}
	else
	{
		printf("else \n");
		for (aux = *N; aux != NULL; aux = aux->proximo)
		{
			if (aux->proximo == NULL)
			{
				printf("AUX->proximo = NULL,ultimo elemento da lista\n");
				aux->proximo = novo;
				novo->proximo = NULL;
				printf("foi-te\n");
				return;
			}
			else
			{
				printf("Aux->proximo !=NULL \n");
				prox = aux->proximo;
			}
			if (lin <= prox->li && colu <= prox->col)
			{
				printf("Coluna < proximo->col\n");
				novo->proximo = prox;
				aux->proximo = novo;
				return;
			}
		}
	}
}

void tamanhoMatriz()
{
	printf("Informe o tamanho das matrizes\n");
	printf("Linhas: ");
	scanf("%d", &linhas);
	printf("Colunas: ");
	scanf("%d", &colunas);
}

int linhacoluna(Matriz_Esparsa **N)
{
	int linha = linhas + 1, coluna = colunas + 1, resp;
	float numero;

	printf("Deseja inserir em qual linha? ");
	while (linha >= linhas || linha < 0)
	{
		scanf("%d", &linha);
		if (linha >= linhas || linha < 0)
		{
			printf("Linha fora do limite da Matriz, entre com dados corretos: ");
			// scanf("%d",&linha);
		}
	}
	printf("Deseja inserir em qual Coluna? ");
	while (coluna >= colunas || coluna < 0)
	{
		scanf("%d", &coluna);
		if (coluna >= colunas || coluna < 0)
		{
			printf("Coluna fora do limite da Matriz, entre com dados corretos: ");
			// scanf("%d",&coluna);
		}
	}
	printf("Qual o conteudo desta celula? ");
	scanf("%f", &numero);
	if (numero != 0)
		insereOrdLista(N, numero, linha, coluna);
	printf("Deseja inserir mais valores na Matriz? <1> SIM <outro valor> NAO: ");
	// imprimeEsparsa(N);
	scanf("%d", &resp);
	return (resp);
}

void imprime_lista_ecandeada(Matriz_Esparsa *N)
{
	Matriz_Esparsa *aux;

	if (N == NULL)
		printf("\n A lista esta vazia!!");
	else
	{
		for (aux = N; aux != NULL; aux = aux->proximo)
		{
			printf("dado: %d \n", aux->dado);
			printf("linha: %d | Coluna: %d\n\n", aux->li, aux->col);
		}
	}
}

void imprimeEsparsa(Matriz_Esparsa *N)
{
	int i, j;
	float achou;
	Matriz_Esparsa *aux;

	if (N == NULL)
	{
		printf("A lista esta vazia!! \n");
		return;
	}
	else
	{
		for (i = 0; i < linhas; i++)
		{
			printf(" |");
			for (j = 0; j < colunas; j++)
			{
				for (aux = N; aux != NULL; aux = aux->proximo)

					if (aux->li == i && aux->col == j)
					{
						achou = aux->dado;
						printf("|  %.2f  |", aux->dado);
					}

				if (achou == 0)
					printf("|  0.00  |");
				achou = 0;
			}
			printf("|\n");
		}
	}
}

void busca_nodo(Matriz_Esparsa *N, float valor)
{
	int found;
	found = 0;
	Matriz_Esparsa *aux;

	if (N == NULL)
		printf("A lista esta vazia!!\n");
	else
	// printf("else busca\n");
	{
		for (aux = N; aux != NULL; aux = aux->proximo)
		{
			if (aux->dado == valor)
			{
				printf("Valor %f Encontrado!\n Linha → %d\n Coluna → %d \n\n", valor, aux->li, aux->col);
				found = 1;
			}
		}
		if (found == 0)
			printf("Nada encontrado");
	}
}

void deleta_matriz(Matriz_Esparsa *N)
{
	Matriz_Esparsa *aux;
	for (aux = N; aux != NULL; aux = aux->proximo)
	{
		free(aux);
	}
	N = NULL;
	printf("Matriz Deletada com Sucesso!");
}

void transposta(Matriz_Esparsa *N, Matriz_Esparsa **R)
{
	Matriz_Esparsa *aux;
	int dado, linha, coluna;
	if (N == NULL)
		printf("A lista esta vazia!!\n");
	else

		for (aux = N; aux != NULL; aux = aux->proximo)
		{
			dado = aux->dado;
			linha = aux->col;
			coluna = aux->li;
			insereOrdLista(R, dado, linha, coluna);
		}
}

void imprime_diagonal(Matriz_Esparsa *N)
{
	int i, j, achou, valor;
	Matriz_Esparsa *aux;
	achou = 0;

	if (N == NULL)
	{
		printf("A lista esta vazia!! \n");
		return;
	}
	else
	{
		for (i = 0; i < linhas; i++)
		{
			printf(" |");
			for (j = 0; j < colunas; j++)
			{
				for (aux = N; aux != NULL; aux = aux->proximo)

					if (aux->li == aux->col && i == j && aux->li == i)
					{
						achou = aux->dado;
						printf("|  %.2f  |", aux->dado);
					}

				if (achou == 0)
					printf("|  0.00  |");
				achou = 0;
			}
			printf("|\n");
		}
	}
}

void somadois(Matriz_Esparsa **A, Matriz_Esparsa **B, Matriz_Esparsa **R)
{
	Matriz_Esparsa *auxA;
	Matriz_Esparsa *auxB;
	int dado, linha, coluna, i, j;
	float achouA = 0;
	float achouB = 0;

	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			busca_posi(A, i, j, &achouA);
			busca_posi(B, i, j, &achouB);
			if (achouA != 0 && achouB != 0)
			{
				printf("achouA=achouB\n");
				dado = (achouA + achouB);
				linha = i;
				coluna = j;
				insereOrdLista(R, dado, linha, coluna);
			}
			else if (achouA + achouB == achouA && achouA != 0)
			{
				printf("A+B=A\n");
				dado = achouA;
				linha = i;
				coluna = j;
				insereOrdLista(R, dado, linha, coluna);
			}
			else if (achouB + achouA == achouB && achouB != 0)
			{
				printf("B+A=B\n");
				dado = achouB;
				linha = i;
				coluna = j;
				insereOrdLista(R, dado, linha, coluna);
			}
		}
	}
}

void soma(Matriz_Esparsa *A, Matriz_Esparsa *B, Matriz_Esparsa **R)
{
	Matriz_Esparsa *auxA;
	Matriz_Esparsa *auxB;
	int dado, linha, coluna, i, j;

	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			for (auxA = A; auxA != NULL; auxA = auxA->proximo)
			{
				for (auxB = B; auxB != NULL; auxB = auxB->proximo)
				{
					if (auxA->li == auxB->li && auxA->col == auxB->col)
					{
						dado = (auxA->dado + auxB->dado);
						linha = auxA->li;
						coluna = auxA->col;
						insereOrdLista(R, dado, linha, coluna);
					}
					else if (auxA->li == i && auxB->li != i && auxA->col == j && auxB->col != j)
					{

						dado = auxA->dado;
						linha = auxA->li;
						coluna = auxA->col;
						insereOrdLista(R, dado, linha, coluna);
					}
					else if (auxA->li != i && auxB->li == i && auxA->col != j && auxB->col == j)
					{
						dado = auxB->dado;
						linha = auxB->li;
						coluna = auxB->col;
						insereOrdLista(R, dado, linha, coluna);
					}
				}
			}
		}
	}
}

void menu()
{
	int resp1, resp2, resp3, opt, valor, meme;
	int aux = 0;
	float valor2 = 0;
	resp2 = 1;
	meme = 0;
	Matriz_Esparsa *ExtA;
	Matriz_Esparsa *ExtB;
	Matriz_Esparsa *ExtR;
	Matriz_Esparsa *p;
	// printf("entrou\n");
	inicializa_lista(&ExtA);
	inicializa_lista(&ExtB);
	inicializa_lista(&ExtR);
	inicializa_lista(&p);

	while (meme == 0)
	{
		resp2 = 1;
		printf("\n01. Criar Matriz");
		printf("\n02. Pesquisar valores");
		printf("\n03. Excluir Matriz (limpar memoria)");
		printf("\n04. Imprimir Matrizes");
		printf("\n05. Somar Matriz A com Matriz B");
		printf("\n06. Subtrair Matrizes");
		printf("\n07. Multiplicar Matrizes");
		printf("\n08. Gerar Matriz transposta");
		printf("\n09. Imprimir a diagonal principal da Matriz");
		printf("\n\n------Funcoes DEBUG -------");
		printf("\n10. Somar dois [outro codigo]");
		printf("\n11. Buscar posicao no nodo");
		printf("\n12. Imprimir Lista encadeada");
		printf("\n0. sair\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			while (resp3 != 1 || resp3 != 2)
			{
				// resp2=0;
				printf("Deseja criar a Matriz 1 ou 2? ");
				scanf("%d", &resp3);
				if (resp3 == 1)
				{
					inicializa_lista(&ExtA);
					printf("Deseja inserir valores na Matriz A? <1> SIM <outro valor> NAO: ");
					scanf("%d", &resp1);
					if (resp1 == 1)
					{
						while (resp2 == 1)
						{
							resp2 = linhacoluna(&ExtA);
						}
						break;
					}
				}
				else if (resp3 == 2)
				{
					inicializa_lista(&ExtB);
					printf("Deseja inserir valores na Matriz B? <1> SIM <outro valor> NAO: ");
					scanf("%d", &resp1);
					if (resp1 == 1)
					{
						while (resp2 == 1)
						{
							resp2 = linhacoluna(&ExtB);
						}
						break;
					}
				}
				else
				{
					printf("Informe 1 ou 2! \n");
				}
			}
			break;
		case 2:
			printf("\nEm qual Matriz deseja buscar?");
			scanf("%d", &resp1);
			if (resp1 == 1)
			{

				printf("Matriz A entao sera!\n");
				printf("Busca de valores:\n");
				printf("Entre com o valor a ser buscado:\n");
				scanf("%f", &valor2);
				busca_nodo(ExtA, valor2);
				break;
			}
			else if (resp1 == 2)
			{

				printf("Matriz B entao sera!\n");
				printf("Busca de valores:\n");
				printf("Entre com o valor a ser buscado:\n");
				scanf("%f", &valor2);
				busca_nodo(ExtB, valor2);
				break;
			}
			// else if(respA=='R' || 'r')
			// 	busca_nodo(&ExtR, val);
		case 4:

			printf("E S P A R S A |A|\n\n");
			imprimeEsparsa(ExtA);
			printf("\n");
			printf("E S P A R S A |B|\n\n");
			imprimeEsparsa(ExtB);
			printf("\n");
			printf("E S P A R S A |R|\n\n");
			imprimeEsparsa(ExtR);
			printf("\n");
			break;
		case 3:
			resp1 = 0;
			resp2 = 0;
			printf("Qual Matriz voce gostaria de deletar? \n 1 → |A| \n 2 → |B| \n");
			scanf("%d", &resp1);
			if (resp1 == 1)
			{
				printf("Voce ira deletar a matriz A, tem certeza disso? \n 1|SIM| \n 2|NAO| \n");
				scanf("%d", &resp2);
				if (resp2 == 1)
				{
					deleta_matriz(ExtA);
					break;
				}
				else
					break;
			}
			else if (resp1 == 2)
			{
				scanf("%d", &resp2);
				printf("Voce ira deletar a matriz B, tem certeza disso? \n 1|SIM| \n 2|NAO| \n");
				if (resp2 == 1)
				{
					deleta_matriz(ExtB);
					break;
				}
				else
					break;
			}

		case 8:
			printf("Qual Matriz voce gostaria de transpor? \n 1 → |A| \n 2 → |B|");
			scanf("%d", &resp1);
			while (aux == 0)
			{
				if (resp1 == 1)
				{
					printf("Transpondo matriz A!\n");
					if (ExtR != NULL)
						deleta_matriz(ExtR);
					inicializa_lista(&ExtR);
					transposta(ExtA, &ExtR);

					imprimeEsparsa(ExtR);
					aux = 1;
				}
				else if (resp1 == 2)
				{
					printf("Transpondo matriz B!\n");
					if (ExtR != NULL)
						deleta_matriz(ExtR);
					inicializa_lista(&ExtR);
					transposta(ExtB, &ExtR);

					imprimeEsparsa(ExtR);
					aux = 1;
				}
				else
					printf("Opcao incorreta\n");
			}
			break;

		case 9:
			aux = 0;
			resp1 = 0;
			while (aux == 0)
			{
				printf("Qual Matriz? [A] → 1\n [B]→2 \n [R]→3 \n");
				scanf("%d", &resp1);
				if (resp1 == 1)
				{
					imprime_diagonal(ExtA);
					aux = 1;
				}
				else if (resp1 = 2)
				{
					imprime_diagonal(ExtB);
					aux = 1;
				}
				else if (resp1 = 3)
				{
					imprime_diagonal(ExtR);
					aux = 1;
				}
				else
					printf("Entre com dados coerentes\n");
			}
			break;

		case 5:

			printf("Somando as matrizes!\n");
			if (ExtR != NULL)
				deleta_matriz(ExtR);
			else
				inicializa_lista(&ExtR);
			soma(ExtA, ExtB, &ExtR);
			imprimeEsparsa(ExtR);
			break;

		case 10:

			printf("Soma 2!\n");
			if (ExtR != NULL)
				deleta_matriz(ExtR);
			else
				inicializa_lista(&ExtR);
			somadois(&ExtA, &ExtB, &ExtR);
			printf("\n");
			imprimeEsparsa(ExtR);
			break;

		case 11:
			valor2 = 0;
			printf("Buscar posicao no nodo\n");
			printf("Matriz: 1, 2, R[3]\n");
			scanf("%d", &resp3);
			if (resp3 == 1)
				p = ExtA;
			else if (resp3 == 2)
				p = ExtB;
			else if (resp3 == 3)
				p = ExtR;
			else
				printf("Alternativa invalida\n");
			printf("linha:");
			scanf("%d", &resp1);
			printf("coluna:");
			scanf("%d", &resp2);
			busca_posi(&p, resp1, resp2, &valor2);
			printf("%f\n", valor2);
			break;

		case 12:
			printf("Imprimir lista encadeada, escolha a lista: A[1] B[2] R[3]\n");
			scanf("%d", &resp1);
			if (resp3 == 1)
				p = ExtA;
			else if (resp3 == 2)
				p = ExtB;
			else if (resp3 == 3)
				p = ExtR;
			else
				printf("Alternativa invalida\n");
			imprime_lista_ecandeada(p);
			break;

		case 0:

			printf("Ate mais!\n");
			return;
		}
	}
}

void main(void)
{
	printf("Primeiramente, defina o tamanho das matrizes:\n");
	tamanhoMatriz();
	menu();
}
