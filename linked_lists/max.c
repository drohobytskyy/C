#include"addandprint.c"

int max (LInt l) {

	int m = 0;
	LInt start = l;

	while(l)
	{
		l = l->prox;
		
		if(l)
			m = m > l->valor ? m : l->valor;
	}
	
	return m;

}

int main () {

	LInt l = NULL;

	add(&l,1);
	add(&l,2);
	add(&l,4);
    add(&l,3);

	print(l);

	int r = max(l);

	printf("max: %d\n",r);

	return 0;	

}
