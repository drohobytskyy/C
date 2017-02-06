#include<stdio.h>


int unionSet (int n, int v1[n], int v2[n], int r[n]) {

	int i = 0, j = 0, c = 0;

	while (c < n)
	{
		r[c] = v1[c];
		c++;
	}

	while (i < n)
	{
		j = 0;

		while (j < n)
		{

			if (j == n-1 && v2[i] != v1[j])
			{
				r[c] = v2[i];
				c++;
				printf("v2: %d | j: %d\n",v2[i], j);
				break;
			}

			if (v2[i] != v1[j])
			{
				 j++;
				 printf("v2: %d | j: %d\n",v2[i], j);
			}
			else
				break;

		}

		i++;
	}

	printf("c: %d\n",c);
	return c;

}


int main () {

	int n = 5, i = 0, j = 0, c = 0, v1[n], v2[n], r[n];

	while(i < n)
	{
		scanf("%d",&v1[i]);
		i++;
	}

	printf("\n");

	while(j < n)
	{
		scanf("%d",&v2[j]);
		j++;
	}

	printf("\n");

	c = unionSet(n,v1,v2,r);

	i = 0;

	while(i < c)
	{
		printf("%d\n",r[i]);
		i++;
	}

	return 0;

}
