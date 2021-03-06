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

LInt elements_level(ABin a, int n);

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


void at_level(ABin a, int d, int c, LInt *l) {

	if(a)
	{
		if(d == c)
		{
			addL(&(*l), a->valor);
		}
		else
		{		
			at_level(a->esq,d,c+1,l);
			at_level(a->dir,d,c+1,l);
		}
	}

}


LInt elements_level(ABin a, int n) {

	int c = 1;
	LInt l = NULL;

	at_level(a,n,c,&l);

	return l;

}

void fromList(LInt l, ABin *a) {

	while(l)
	{
		add(&(*a), l->valor);
		l = l->prox;
	}

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
	int n = 3 ;
	addL(&l,5);
	addL(&l,3);
	addL(&l,7);
	addL(&l,4);
	addL(&l,6);

	printL(l);;
	
	fromList(l,&a);
	
	draw(a,1);

	return 0;

}
