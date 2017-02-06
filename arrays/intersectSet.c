#include<stdio.h>


int intersectSet (int n, int v1[n], int v2[n], int r[n]) {

	int i = 0, j = 0, c = 0;

	while (i < n)
	{
		j = 0;

		while (j < n)
		{
			if (v1[i] == v2[j])
			{
				r[c] = v1[i];
				c++;
				break;
			}
		
			j++;

		}

		i++;
	}

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

	c = intersectSet(n,v1,v2,r);

	i = 0;

	while(i < c)
	{
		printf("%d\n",r[i]);
		i++;
	}

	return 0;

}
