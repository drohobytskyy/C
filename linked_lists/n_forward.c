#include"addandprint.c"

LInt n_farward(LInt l, int n) {

	int i = 0;

	for(i = 0; i < n; i++)
	{
		l = l->prox;
	}

	return l;

}

int main () {


	return 0;


}
