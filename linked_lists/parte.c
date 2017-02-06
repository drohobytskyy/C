#include<stdio.h>
#include<stdlib.h>

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

}Node;

int length(LInt l);

LInt parte(LInt l) {

	LInt prev = NULL;

	int i = (length(l))/2, j = 0;

	while(j < i)
	{
		prev = l;

		l = l->prox;

		j++;
	}
	
	prev->prox = NULL;

	return l;
	
}

int length(LInt l) {

	int r = 0;

	while(l != 0)
	{
		l = l->prox;
		r++;
	}

	return r;
}

void print(LInt l) {

	while(l)
	{
		printf("%d->",l->valor);
		l = l->prox;
	}

	printf("NULL\n");

}

void insere(LInt *l, int x) {

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

int main() {

	LInt x = NULL, y = NULL;

	insere(&y,1);
	insere(&y,2);
	insere(&y,3);
	insere(&y,4);
	insere(&y,5);

	print(y);

	x = parte(y);

	print(x);

	print(y);

	return 0;

}

