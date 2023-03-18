#include "arvorebinaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 100

tArvore *criar_arvore() {
  tArvore *novaArvore = (tArvore *)malloc(sizeof(tArvore));
  novaArvore->raiz = NULL;
  return novaArvore;
}

tNo *_inserir_no(tNo *no, int dado) {
  if (no == NULL) {
    tNo *novoNo = (tNo *)malloc(sizeof(tNo));
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
  } else {
    if (dado < no->dado)
      no->esquerda = _inserir_no(no->esquerda, dado);
    else if (dado > no->dado)
      no->direita = _inserir_no(no->direita, dado);
    return no;
  }
}

tArvore *inserir(tArvore *arvore, int dado) {
  if (arvore->raiz == NULL) {
    arvore->raiz = _inserir_no(arvore->raiz, dado);
  } else {
    _inserir_no(arvore->raiz, dado);
  }
  return arvore;
}

tArvore *remover_no(tArvore *raiz, int dado) {
  if (raiz == NULL)
    return raiz;

  if (dado < (*raiz).raiz)
    raiz->esquerda = remover_no(raiz->esquerda, dado);
  else if (dado > (*raiz).raiz)
    raiz->direita = remover_no(raiz->direita, dado);
  else {
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
      free(raiz);
      raiz = NULL;
    } else if (raiz->esquerda == NULL) {
      tArvore *temp = raiz;
      raiz = raiz->direita;
      free(temp);
    } else if (raiz->direita == NULL) {
      tArvore *temp = raiz;
      raiz = raiz->esquerda;
      free(temp);
    } else {
      tNo *temp = (*raiz).esquerda;
      while (temp->direita != NULL)
        temp = temp->direita;
      (*raiz).raiz = (*temp).dado;
      temp->dado = dado;
      raiz->esquerda = remover_no(raiz->esquerda, dado);
    }
  }
  return raiz;
}

void imprimir_em_ordem(tArvore *arvore) {
  if (arvore != NULL) {
    imprimir_em_ordem((*arvore).esquerda);
    printf("%d ", (*arvore).raiz->dado);
    imprimir_em_ordem((*arvore).direita);
  }
}

void imprimir_pre(tArvore *arvore) {
  if (arvore != NULL) {
    printf("%d ", arvore->raiz->dado); // corrigido aqui
    imprimir_pre(arvore->esquerda);
    imprimir_pre(arvore->direita);
  }
}

void imprimir_pos(tArvore *arvore) {
  if (arvore != NULL) {
    imprimir_pos(arvore->esquerda);
    imprimir_pos(arvore->direita);
    printf("%d ", arvore->raiz->dado);
  }
}

void imprimir(tArvore *arvore, int nivel) {
  if (arvore == NULL)
    return;

  imprimir(arvore->direita, nivel + 1);

  for (int i = 0; i < nivel; i++)
    printf("   ");

  printf("%d\n", arvore->raiz->dado);

  imprimir(arvore->esquerda, nivel + 1);
}

void liberar(tArvore *arvore) {
  if (arvore != NULL) {
    liberar(arvore->esquerda);
    liberar(arvore->direita);
    free(arvore);
  }
}

// função para verificar se a árvore foi alterada
void arvore_alterada() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char str[MAX_LENGTH];
  strftime(str, MAX_LENGTH, "%c", tm);
  printf("\nArvore alterada em: %s\n", str);
}
