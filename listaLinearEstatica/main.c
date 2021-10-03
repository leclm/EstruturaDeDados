#include "listaEstatica.c"
#include <stdlib.h>
#include <stdio.h>

// Fn + F6

void main() {
  Tipo_Lista LE;

	LE.inicio = 0;
	LE.fim = 0;

	insere_fim_lista(&LE, 10);
  insere_fim_lista(&LE, 20);
  insere_fim_lista(&LE, 30);
  insere_fim_lista(&LE, 40);
  imprime_lista(LE);
  exclui_elem_lista(&LE, 1);
  imprime_lista(LE);
  exclui_elem_lista(&LE, 2);
  imprime_lista(LE);
  insere_fim_lista(&LE, 90);
  imprime_lista(LE);
}