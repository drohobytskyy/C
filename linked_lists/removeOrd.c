#include<stdio.h>
#include<stdlib.h>

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

} Node;

int removeOrd(LInt *l, int x) {

	LInt jailed;
	while(*l)
	{
		if ((*l)->valor == x)
		{
			jailed = *l;
			*l = (*l)->prox;
			free(jailed);
			return 1;
		}
		else
		{
			l = &((*l)->prox);
		}
	}


	return 0;

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


void print(LInt l) {

	while(l)
	{
		printf("%d->",l->valor);
		l = l->prox;
	}

	printf("NULL\n");

}


int main() {

	int r = 0;
	LInt l;
	l = NULL;

	insere(&l,1);
	insere(&l,2);
	insere(&l,3);
	insere(&l,2);

	print(l);

	r = removeOrd(&l,2);

	print(l);

	return 0;

}
