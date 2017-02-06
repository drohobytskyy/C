#include<stdio.h>
#include<stdlib.h>


typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

} Node;

void imprime (LInt l) {

	while (l != NULL)
	{
		printf("%d\n",l->valor);
		l = l->prox;
	}

}

LInt newNode(int x, LInt l) {

	Node *new;
	new = malloc(sizeof(Node*));
	new->valor = x;
	new->prox = l;

	return new;
}

LInt snoc(LInt l, int x) {

	if(l == NULL)
		return newNode(x,NULL);
	else
	{
		l->prox = snoc(l->prox, x);
		return l;
	}
	
}

int main ()
{
	LInt l;
	l = NULL;
	l = snoc(l,1);
	l = snoc(l,2);

	imprime(l);
	imprime(l);
	return 0;
}
