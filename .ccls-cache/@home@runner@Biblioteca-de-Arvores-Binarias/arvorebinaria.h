#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

// estrutura para um nó da árvore
typedef struct no {
  int dado;
  struct no *esquerda;
  struct no *direita;
} tNo;

// tipo abstrato de dados para a árvore
typedef struct arvore {
  tNo *raiz;
  struct arvore *esquerda;
  struct arvore *direita;
} tArvore;

// funções
tArvore *criar_arvore();
tArvore *inserir(tArvore *arvore, int dado);
tNo *_inserir_no(tNo *no, int dado);
tArvore *remover_no(tArvore *raiz, int dado);
void imprimir_em_ordem(tArvore *arvore);
void imprimir_pre(tArvore *arvore);
void imprimir_pos(tArvore *arvore);
void imprimir(tArvore *arvore, int nivel);
void liberar(tArvore *arvore);
void arvore_alterada();
#endif // ARVOREBINARIA_H