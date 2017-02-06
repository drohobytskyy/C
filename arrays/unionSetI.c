#include<stdio.h>


int unionSetI (int n, int v1[n], int v2[n], int r[n]) {

	int i = 0, j = 0, c = 0;

	while (i < n && j < n)
	{
		if (v1[i] == 1 || v2[j] == 1)
		{
			r[c] = 1;
		}
		else
		{
			r[c] = 0;
		}
			
		printf("r: %d | j: %d\n",r[c], j);
		c++;
		j++;
		i++;
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

	c = unionSetI(n, v1, v2, r);

	i = 0;

	while(i < c)
	{
		printf("%d\n",r[i]);
		i++;
	}

	return 0;

}
