#include<stdio.h>
#include<stdlib.h>

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

}Node;

void init(LInt *l) {

	int i = 0, c = 0;
	LInt start = *l;
	
	while(*l)
	{
		l = &(*l)->prox;
		c++;
	}

	*l = start;

	while(i < c-1)
	{
		l = &(*l)->prox;
		i++;
	}

	*l = NULL;

}

void add(LInt *l, int x) {

	LInt new;
	new = malloc(sizeof(Node*));
	new->valor = x;
	new->prox = NULL;

	while(*l)
	{
		l = &(*l)->prox;
	}

	*l = new;

}

void print (LInt l) {

	while(l)
	{
		printf("%d->",l->valor);
		l = l->prox;
	}

	printf("NULL\n");

}

int main () {

	LInt l = NULL;

	add(&l,1);
	add(&l,2);
	add(&l,3);
	add(&l,4);

	print(l);

	init(&l);

	print(l);

	return 0;

}
