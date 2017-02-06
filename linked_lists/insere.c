#include<stdio.h>
#include<stdlib.h>

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

} Node;


void insere(LInt *l, int x) {

	LInt new;
	new = malloc(sizeof(Node*));
	new->valor = x;
	new->prox = NULL;

	while((*l) != NULL)
	{
		l = &(*l)->prox;
	}
	
	*l = new;
}


void print(LInt l) {

	while(l != NULL)
	{
		printf("%d->",l->valor);
		l = l->prox;
	}

	printf("NULL\n");

}


int main() {

	LInt l;
	l = NULL;

	insere(&l,1);
	insere(&l,2);

	print(l);

	return 0;

}
