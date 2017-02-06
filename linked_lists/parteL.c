#include"addandprint.c"

LInt parteL(LInt l) {

	int n = 1;
	LInt newHead = NULL;
	LInt newPrev = NULL;
	LInt prev = NULL;

	for (n = 1; l; n++,l=l->prox)
	{
		if(n % 2 == 0)
		{
			if(!newHead)
				newHead = l;
			if(!newPrev)
				newPrev = l;
			else
			{
				newPrev->prox = l;
				newPrev = newPrev->prox;
			}
		}
		else
		{
		
			if(!prev)
				prev = l;
			else
			{
				prev->prox = l;
				prev = prev->prox;
			}

		}		
	}
	
	newPrev->prox = NULL;
	return newHead;

}


int main () {

	LInt y, x;
	x = y = NULL;

	add(&y,1);
	add(&y,2);
	add(&y,3);
	add(&y,4);
	add(&y,5);

	print(y);

	x = parteL(y);

	print(x);

	print(y);

	return 0;

}
