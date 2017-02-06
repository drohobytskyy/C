#include"addandprint.c"

LInt rotate(LInt l) {

	int temp;
	LInt head = l;

	while(l && l->prox)
	{
		temp = l->valor;
		l->valor = l->prox->valor;
		l->prox->valor = temp;
		l = l->prox;
	}

	return head;

}


int main () {

	LInt l = NULL;
	
	add(&l,1);
	add(&l,2);
	add(&l,3);
	add(&l,4);
	add(&l,5);

	print(l);
	
	l = rotate(l);

	print(l);
	return 0;

}
