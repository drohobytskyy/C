#include<stdio.h>

int trailingZeros(int unsigned n);

int main () {

	int unsigned n;
	int unsigned r;

	scanf("%d",&n);

	r = trailingZeros(n);

	printf("result: %d\n",r);

	return 0;

}

int trailingZeros(int unsigned n) {

	int c;

	while(n % 2 == 0)
	{
		c++;
		n = n>>1;
		printf("%d\n",n);
	}

	return c;

}
