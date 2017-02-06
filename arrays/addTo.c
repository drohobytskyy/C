#include<stdio.h>

void addTo (int n, int m, int a[n][m], int b[n][m]) {

	int i = 0, j = 0;

	while (i < n)
	{
		j = 0;

		while (j < m)
		{
			a[i][j] = a[i][j] + b[i][j];
			j++;
		}

		i++;
	}

}


int main () {

	int n = 2, m = 2, i = 0, j = 0, a[n][m], b[n][m];

	while (i < n)
	{
		j = 0;
		
		while (j < m)
		{
			scanf("%d", &a[i][j]);
			j++;
		}

		i++;
	}

	printf("\n");

	i = 0; j = 0;

	while (i < n)
	{
		j = 0;

		while (j < m)
		{
			scanf("%d",&b[i][j]);
			j++;
		}

		i++;
	}

	printf("\n");

	addTo(n,m,a,b);

	i = 0; j = 0;

	while (i < n)
	{
		j = 0;

		while (j < m)
		{	
			printf("%d\n",a[i][j]);
			j++;
		}

		i++;
	}

	return 0;

}
