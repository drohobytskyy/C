#include<stdio.h>


void sumdiag (int n, int m[n][n]) {

	int i = 0, j = 0, sum = 0;

	while (i < n)
	{
		j = 0;
		
		while (j < n)
		{
			sum += m[i][j];
			j++;
		}

		m[i][i] = sum - m[i][i];
		i++;
		sum = 0;
	}

}


int main () {

	int i = 0, j = 0, n = 4, m[n][n];

	while (i < n)
	{
		j = 0;
		
		while (j < n)
		{
			scanf("%d",&m[i][j]);
			j++;
		}

		i++;
	}

	printf("\n");

	sumdiag(n,m);

	i = 0; j = 0;

	while(i < n)
	{
		j = 0;

		while(j < n)
		{
			printf("%d\n",m[i][j]);
			j++;
		}

		i++;
	}
	
	return 0;

}
