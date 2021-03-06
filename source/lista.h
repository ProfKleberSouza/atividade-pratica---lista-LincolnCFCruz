#ifndef lista
#define lista 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Produto{
  int codigo;
  char descricao[100];
  float valor;
  int quantidade;
}Produto;

typedef struct Celula{
  Produto dado;
  struct Celula *prox;
}Celula;

Celula *new_celula(){
  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->prox = NULL;
  return tmp;
}

typedef struct Lista{
  Celula *inicio;
  Celula *fim;
  int tam;
}Lista;

void new_lista(Lista *l){

  l->inicio = l->fim = new_celula();
  l->tam = 0;

}

#endif
