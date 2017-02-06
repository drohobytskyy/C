#include<stdio.h>


int trisup (int n, int m [n][n]) {

	int i = 0, j = 0, r = 0;

	while (i < n)
	{
		j = 0;

		while(j < n)
		{
			printf("i: %d | j: %d | m[i][j]: %d\n",i, j, m[i][j]);
			if (i > j)
			{
				printf("(i>j) | i: %d | j: %d | m[i][j]: %d\n",i, j, m[i][j]);
				
				if (m[i][j] == 0)
					r = 1;
				else
				{
					r = 0;
					break;
				}

			}
			
				j++;

		}

		if(r == 1)
			i++;
		else
			break;
	}

	return r;
}


int main () {

	int n = 3, r = 0, i = 0, j = 0;
	int m [n][n];

	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			scanf("%d",&m[i][j]);
			printf("i: %d | j: %d | m[i][j]: %d\n",j,i,m[i][j]);
			j++;
		}
		i++;
	}

	printf("\n");

	r = trisup(n,m);

	printf("r: %d\n",r);

	return 0;

}
