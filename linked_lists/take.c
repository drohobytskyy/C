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

int take(int x, LInt *l) {

	int c = length (&(*l)), i = c - x, j = 0;
	LInt temp = NULL, f = NULL;

	printf("%d\n",c);

	if(x < c)
	{
		while(j < i)
		{
			
			l = &(*l)->prox;
			j++;
		}
		temp = (*l)->prox;
		*l = NULL;

		while(temp)
		{
			f = temp;
			temp = temp->prox;
			free(temp);
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
	
	int r = take(3,&l);

	print(l);

	return 0;

}
