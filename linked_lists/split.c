#include<stdio.h>
#include<stdlib.h>

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

} Node;


void split(LInt l, int x, LInt *mx, LInt *Mx) {

	LInt prev, temp;
	prev = NULL;
	temp = l;
	*mx = l;

	while(l->valor != x && l != NULL)
	{
		if (l->prox != NULL)
		{
			prev = l;
			l = l->prox;
		}
	}

	*Mx = l;
	prev->prox = NULL;

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

	LInt l, mx, Mx;
	l = NULL;
	mx = NULL;
	Mx= NULL;

	insere(&l,1);
	insere(&l,2);
	insere(&l,3);
	insere(&l,4);

	print(l);

	split(l,3,&mx,&Mx);

	print(mx);
	print(Mx);

	int x;

	return 0;
	
}
