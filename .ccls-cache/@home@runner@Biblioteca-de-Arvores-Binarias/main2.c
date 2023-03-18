#include "arvorebinaria.h"
#include <stdio.h>

int main() {
  tArvore *arvore = criar_arvore();

  // Insere alguns valores na árvore
  inserir(arvore, 8);
  inserir(arvore, 3);
  inserir(arvore, 10);
  inserir(arvore, 1);
  inserir(arvore, 6);
  inserir(arvore, 14);
  inserir(arvore, 4);
  inserir(arvore, 7);
  inserir(arvore, 13);

  // Imprime a árvore em ordem
  printf("Arvore em ordem:\n");
  imprimir_em_ordem(arvore);
  printf("\n");

  // Imprime a árvore em pré-ordem
  printf("Arvore em pre-ordem:\n");
  imprimir_pre(arvore);
  printf("\n");

  // Imprime a árvore em pós-ordem
  printf("Arvore em pos-ordem:\n");
  imprimir_pos(arvore);
  printf("\n");

  // Imprime a árvore de forma mais visual
  printf("Arvore visualmente:\n");
  imprimir(arvore, 0);

  // Remove um nó da árvore
  remover_no(arvore, 6);

  // Imprime a árvore em ordem novamente
  printf("Arvore em ordem apos remocao do no 6:\n");
  imprimir_em_ordem(arvore);
  printf("\n");

  // Libera a árvore da memória
  liberar(arvore);

  // Informa que a árvore foi alterada
  arvore_alterada();

  return 0;
}
