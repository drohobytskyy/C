#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct arvore *ABin;

typedef struct arvore {
	
	int valor;
	ABin esq, dir;

}Node;

typedef struct lint *LInt;

typedef struct lint {

	int valor;
	LInt prox;

}Nodo;

int elements_level(ABin *a, int n);

ABin new(int v, ABin e, ABin d) {

	ABin new = malloc(sizeof (struct arvore));
	new->valor = v;
	new->esq = e;
	new->dir = d;

	return new;
}

void add(ABin *a, int x) {

	while(*a)
	{
		if(x <= (*a)->valor)
			a = &(*a)->esq;
		else
			a = &(*a)->dir;
	}

	*a = new(x,NULL,NULL);

}

void print(ABin a) {

	if(a)
	{
		print(a->esq);
		printf("%d\n",a->valor);
		print(a->dir);
	}

}

int max(int x, int y) {

	if(x < y)
		x = y;

	return x;

}

int altura(ABin a) {

	int r = 0;

	if(a != NULL)
		r = 1 + max(altura(a->esq), altura(a->dir));

	return r;

}

void addL(LInt *l, int x) {

	LInt new = malloc(sizeof(Nodo*));
	new->valor = x;
	new->prox = NULL;

	while(*l)
	{
		l = &(*l)->prox;
	}
	
	*l = new;
}


void at_level(ABin *a, int d, int c) {

	if(a)
	{
		if(d == c)
		{
			free((*a)->esq);
			free((*a)->dir);
			(*a)->dir = NULL;
			(*a)->esq = NULL;
		}
		else
		{		
			at_level(&(*a)->esq,d,c+1);
			at_level(&(*a)->dir,d,c+1);
		}
	}

}


int elements_level(ABin *a, int n) {

	int c = 1;

	at_level(&(*a),n,c);

	return 0;
	
}

void printL(LInt l) {

	while(l)
	{
		printf("%d->",l->valor);
		l = l->prox;
	}

	printf("NULL\n");

}

void padding(char ch, int n) {

	int i;
	for(i = 0; i < n; i++)
	{
		putchar(ch);
	}

}

void draw(ABin root, int level) {

	int i = 0;

	if(root == NULL)
	{
		padding ('\t', level);
		puts("~");
	}
	else
	{
		draw(root->dir, level+1);
		padding ('\t', level);
		printf("%d\n",root->valor);
		draw(root->esq, level+1);
	}

}

int main () {

	ABin a = NULL;
	LInt l = NULL;
	int r;
	int n = 3;
	add(&a,5);
	add(&a,3);
	add(&a,7);
	add(&a,4);
	add(&a,6);

	print(a);

	r = altura(a);

	printf("altura: %d\n",r);

	draw(a,1);
	
	r = elements_level(&a,2);

	r = 2^(2);

	printf("r: %d\n",r);

	draw(a,1);
	
	return 0;

}
