#include<stdio.h>
#include<stdlib.h>

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

} Node;

void freeL (LInt l) {

	LInt temp;
	while(l != NULL)
	{
		temp = l;
		l = l->prox;
		free (temp);
		l = NULL;
	}

	printf("--Empty--\n");

}

LInt newNode(int x, LInt l){

	Node *new;
	new = malloc(sizeof(Node*));

	new->valor = x;
	new->prox = l;

	return new;

}

LInt snoc(LInt l, int x) {

	if(l == NULL)
		return newNode(x, NULL);
	else
	{
		l->prox = snoc(l->prox,x);
		return l;
	}
}

void show(Node *l) {

	if(l != NULL)
	{
		printf("%d\n",l->valor);
		show(l->prox);
	}

}

int main () {

	int c = 0;
	LInt l;

	l = NULL;

	l = snoc(l,1);
	l = snoc(l,2);
	
	show(l);

	freeL(l);

	l = NULL;

	show(l);

	return 0;

}


