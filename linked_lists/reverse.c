#include<stdio.h>
#include<stdlib.h>

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

} Node;

void print (LInt l);


void reverse(LInt *l) {

	LInt prev = NULL;
	LInt current = *l;
	LInt next;

	while (current != NULL) 
	{
		next = current->prox;
		printf("next: ");
		print(next);

		current->prox = prev;
		printf("current->prox: ");
		print(current->prox);

		prev = current;
		printf("prev: ");
		print(prev);

		current = next;
		printf("current: ");
		print(current);
	}

	*l = prev;

}

void print (LInt l){

	while(l != NULL)
	{
		printf("%d->",l->valor);
		l = l->prox;
	}
	printf("NULL");
	printf("\n");

}

LInt newNode(int x, LInt l) {

	Node *new;
	new = malloc(sizeof(Node*));
	new->valor = x;
	new->prox = l;

	return new;

}

LInt snoc (LInt l, int x) {

	if (l == NULL)
		return newNode(x,NULL);
	else
	{
		l->prox = snoc(l->prox,x);
		return l;
	}

}

int main () {

	LInt l;
	l = NULL;

	l = snoc(l,1);
	l = snoc(l,2);
	l = snoc(l,3);
	l = snoc(l,4);

	print(l);

	reverse(&l);

	print(l);

	return 0;
}
