#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct arvore *ABin;

typedef struct arvore {
	
	int valor;
	ABin esq, dir;

}Node;

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

int iguais(ABin a, ABin b) {

	if(a == NULL && b == NULL)
		return 1;

	if(a != NULL && b != NULL)
	{
		return 
		(
			a->valor == b->valor
			&& iguais(a->esq, b->esq)
			&& iguais(a->dir, b->dir)
		);
	}

	return 0;

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

	ABin a = NULL, b = NULL;
	int r;
	add(&a,5);
	add(&a,3);
	add(&a,7);
	add(&a,4);
	add(&a,6);

	add(&b,5);
        add(&b,3);
        add(&b,7);
        add(&b,4);
        add(&b,6);

	print(a);

	r = altura(a);

	printf("altura: %d\n",r);

	draw(a,1);	

	r = iguais(a,b);

	printf("r: %d\n",r);
	return 0;

}
