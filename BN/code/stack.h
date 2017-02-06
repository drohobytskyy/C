#ifndef ___STACK_H___
#define ___STACK_H___

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define ARRAY_SIZE 10000

/*Etrutura de dados para guardar na stack*/
typedef struct {
	int l;
	int c;
	char s0;
	int num_cmd;
}ELEM;

/*Estrutura da stack*/
typedef struct{
    int n;
	ELEM stack[ARRAY_SIZE];
}STACK;

/*Função que cria uma stack vazia*/
STACK *create_stack();

/*Incicializar stack a zero*/
void init (STACK *);

/*Função que determina o tamanho da stack*/
int size (STACK *s);

/*Função que verifica se a stack está vazia*/
int isEmpty (STACK *s);

/*Função que empilha elementos da stack*/
int push (STACK * s, ELEM i);

/*Função que puxa pra baixo os elementos da stack*/
int pop (STACK *s);

/*Funçao que poe no topo os elementos da stack*/
int top (STACK *s, ELEM *v);

#endif

