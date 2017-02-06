#include<stdio.h>
#include<stdlib.h>

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

}Node;

int removeMaior(LInt *l) {

	int temp = 0, i = 0, c = 0, v;
	LInt start = *l;

	while(*l != NULL)
	{
		l = &(*l)->prox;
		c++;
		if(*l)
			temp = temp > (*l)->valor ? temp : (*l)->valor;
	}

	*l = start;
	
	while(i < c)
	{
		i++;
		if((*l)->valor == temp)
		{
			 v = (*l)->valor;
			*l = (*l)->prox;
			break;
		}
		else
		{
			l = &(*l)->prox;
		}

	}

	*l = NULL;
	return v;

}

void print(LInt l) {

	while(l)
	{
		printf("%d->",l->valor);
		l = l->prox;
	}

	printf("NULL\n");

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

int main() {

	int r = 0;
	LInt l = NULL;

	add(&l,1);
	add(&l,7);
	add(&l,3);
	add(&l,5);

	print(l);

	r = removeMaior(&l);
	printf("valor: %d\n",r);

	print(l);

	return 0;

}
