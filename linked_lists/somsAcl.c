#include"addandprint.c"


LInt somasAlc(LInt l) {

	int c = 0;

	LInt new = NULL;;	

	while(l)
	{
		c += l->valor;
		add(&new,c);
		l = l->prox;
	}

	return new;

}

int main () {

	LInt l;
	l = NULL;

	add(&l,1);
	add(&l,2);
	add(&l,3);
	add(&l,4);

	print(l);

	l = somasAlc(l);

	print (l);

	return 0;

}
