#include"addandprint.h"


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
