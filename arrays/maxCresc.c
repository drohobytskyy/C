#include<stdio.h>


int maxCresc(int v[], int n) {

	int i = 0, c = 1, j = 0, maior = 0;

	while (i < n)
	{
		j = i;

		while (v[j] < v[j+1] && j<n)
		{
			j++;
			c++;
		}

		if(maior > c)
			maior = maior;
		else
			maior = c;


		printf("maior: %d | i: %d | j:%d | c: %d\n",maior, i, j, c);

		i++;
		c = 1;
	}

	return maior;

}


int main() {

	int n = 9, i = 0, r = 0;
	int v[10];

	while (i < n)
	{
		scanf("%d",&v[i]);
		i++;
	}

	printf("\n");

	r = maxCresc(v,n);

	printf("r: %d\n",r);
	return 0;

}
