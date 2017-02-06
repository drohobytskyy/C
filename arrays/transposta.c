#include<stdio.h>


void transposta (int n, int m[n][n]) {

	int i = 0, j = 0;

	int temp[n][n];


	for(i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			temp[i][j] = m[i][j];
		}
	}

	i = 0; j = 0;

	while (i < n)
	{
		j = 0;
		while(j < n)
		{
			m[i][j] = temp[j][i];
			printf("%d\n",m[i][j]);
			j++;
		}

		i++;
	}

	printf("\n");

}


int main () {

	int n = 3, i = 0, j = 0, m[n][n];

	while(i < n)
	{	
		j = 0;
		while(j < n)
		{
			scanf("%d",&m[i][j]);
			j++;
		}

		i++;
	}

	printf("\n");
	
	i = 0; j = 0;

	transposta(n,m);

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
