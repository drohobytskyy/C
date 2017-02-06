#include"addandprint.c"


int listToArray(LInt l, int v[], int n) {

	int i = 0;

	while(i < n)
	{
		v[i] = l->valor;
		l = l->prox;
		i++;
	}

	return i;

}


int main () {

	int v[100], n = 5, i = 0;
	LInt l = NULL;
	int r = 1;
	add(&l,1);
	add(&l,2);
	add(&l,5);
	add(&l,1);
	add(&l,10);

	print (l);

	r = listToArray(l,v,n);

	while(i < n)
	{
		printf("|%d",v[i]);
		i++;
	}
	printf("|\n");

	return 0;

}
