#include<stdio.h>


int cardinalMSet (int n, int v[n]) {

	int i = 0, c = 0, j = 0;

	while(i < n)
	{
		c += v[i];
		i++;
		printf("%d\n",c);
	}

	return c;
}


int main () {

	int i = 0, c = 0, n = 8, v[n];

	while(i < n)
	{
		scanf("%d", &v[i]);
		i++;
	}

	printf("\n");

	c = cardinalMSet(n, v);

	printf("%d\n", c);

	return 0;
	
}
