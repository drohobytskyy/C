#include"addandprint.c"

LInt clone (LInt l) {

	LInt nova, ultima;
	
	if (l == NULL)
		nova = NULL;
	else
	{
		nova = malloc(sizeof(Node*));
		nova->valor = l->valor;
		l = l->prox;
		ultima = nova;

		while(l)
		{
			ultima->prox = malloc(sizeof(Node*));
			ultima = ultima->prox;
			ultima->valor = l->valor;
			l = l->prox;
		}

		ultima->prox = NULL;
	}

	return nova;

}

int main () {

	LInt l = NULL, cl = NULL;

	add(&l,1);
	add(&l,2);

	print(l);

	cl = clone(l);

	print(cl);

	return 0;

}
