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

typedef struct Lista{
  Celula *inicio;
  Celula *fim;
  int tam;
}Lista;

void print_produto(Produto p){
  printf("{%d, %s, %.2f, %d}\n", p.codigo, p.descricao, p.valor, p.quantidade);
}

Celula *new_celula(){
  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->prox = NULL;
  return tmp;
}

void new_lista(Lista *l){
  l->inicio = l->fim = new_celula();
  l->tam = 0;
}

void add_lista_begin(Lista *l, Produto p){
  
  l->inicio->dado = p;
  Celula *tmp = new_celula();

  l->inicio = tmp;
  l->tam++;
}

void add_lista_end(Lista *l, Produto p){
  
  Celula *tmp = new_celula();
  tmp->dado = p;

  l->fim->prox = tmp;
  l->fim = tmp;
  l->tam++;
}

void print_lista(Lista *l){

  Celula *tmp = l->inicio->prox;
  while(tmp != NULL){
    print_produto(tmp->dado);
    tmp = tmp->prox;
  }
}

void delete_lista_cod(Lista *l, int codigo){

  Celula *ant = l->inicio;
  Celula *tmp = l->inicio->prox;

  while(tmp!=NULL && tmp->dado.codigo != codigo){
    ant = ant->prox;
    tmp = tmp->prox;
  }

  if(tmp!=NULL){

    ant->prox = tmp->prox;

    free(tmp);
    tmp = NULL;

    if(ant->prox == NULL){
      l->fim = ant;
    }

    l->tam--;
  }
}

void delete_lista_pos(Lista *l, int pos){

  Celula *ant = l->inicio;
  Celula *tmp = l->inicio->prox;

  while(tmp!=NULL && pos > 0){
    ant = ant->prox;
    tmp = tmp->prox;
    pos--;
  }

  if(tmp!=NULL){

    ant->prox = tmp->prox;

    free(tmp);
    tmp = NULL;

    if(ant->prox == NULL){
      l->fim = ant;
    }

    l->tam--;
  }
}

void delete_lista_begin(Lista *l){
  delete_lista_pos(&l, 0);
}

void delete_lista_end(Lista *l){
  delete_lista_pos(&l, l->tam-1);
}

#endif 
