#include<stdio.h>
#include<stdlib.h>

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

}Node;

int remove_dup(LInt *l) {

	LInt temp, current, dup;

	current = *l;

	while(current != NULL)
	{
		temp = current;

		while(temp->prox)
		{
			if(current->valor == temp->prox->valor)
			{
				dup = temp->prox;
				temp->prox = temp->prox->prox;
				free(dup);
			}
			else
			{
				temp = temp->prox;
			}
		}

		current = current->prox;
	}

	return 1;

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

void print(LInt l) {

	while(l)
	{
		printf("%d->",l->valor);
		l = l->prox;
	}

	printf("NULL\n");

}

int main () {

	LInt l;
	l = NULL;

	add(&l,1);
	add(&l,2);
	add(&l,1);
	add(&l,2);

	print(l);

	remove_dup(&l);

	print(l);

	return 0;

}
