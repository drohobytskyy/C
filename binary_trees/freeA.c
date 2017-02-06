#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct arvore *ABin;

typedef struct arvore {
	
	int valor;
	ABin esq, dir;

}Node;

int aux(int x, int y);

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

int freeA(ABin a){

	int r = 0;

	if(a)
	{
		r = 1 + aux(freeA(a->esq), freeA(a->dir));
		free(a);
	}

	return r;

}

int aux(int x, int y) {

	int r = 0;
	r = x + y;
	return r;

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
	int r;
	add(&a,5);
	add(&a,3);
	add(&a,7);
	add(&a,4);
	add(&a,6);

	print(a);

	r = altura(a);

	printf("altura: %d\n",r);

	draw(a,1);	

	r = freeA(a);

	printf("libertados: %d\n",r);
	
	a = NULL;

	draw(a,1);

	return 0;

}
