#include<stdio.h>


int qdig (int n){

	int r=1;
	if (n < 0)
		n = -n;

	while (n > 9)
	{
		n/=10;
		r++;
	}
	return r;

}


int main () {

	int n;

	scanf("%d",&n);

	n = qdig(n);

	printf("result: %d\n",n);

}
