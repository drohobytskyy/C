#include"addandprint.c"


int length(LInt *l) {

	int c = 0;

	while(*l)
	{
		l = &(*l)->prox;
		c++;
	}

	return c;

}

int drop(int x, LInt *l) {

	int c = length (&(*l)), i = 0;
	LInt temp = NULL;

	printf("%d\n",c);

	if(x < c)
	{
		while(i < x)
		{
			temp = *l;
			*l = (*l)->prox;
			free(temp);
			i++;
		}
	}

	return 0;

}


int main () {


	LInt l = NULL;

	add(&l,1);
	add(&l,3);
	add(&l,5);
	add(&l,2);
	add(&l,7);


	print(l);
	
	int r = drop(3,&l);

	print(l);

	return 0;

}
