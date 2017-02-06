#include<stdio.h>


int unionMSet (int n, int v1[n], int v2[n], int r[n]) {

	int i = 0, c = 0;

	while(i < n)
	{
		r[c] = v1[i] + v2[i];
		i++;
		c++;
	}

	return c;

}


int main () {


	int i = 0, j = 0, c = 0, n = 8, v1[n], v2[n], r[n];

	while(i < n)
	{
		scanf("%d", &v1[i]);
		i++;
	}

	printf("\n");

	while(j < n)
	{
		scanf("%d",&v2[j]);
		j++;
	}

	printf("\n");

	c = unionMSet(n, v1, v2, r);

	i = 0;

	while (i < c)
	{
		printf("%d\n", r[i]);
		i++;
	}

	return 0;

}
