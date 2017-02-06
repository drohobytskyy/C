#include<stdio.h>


int minInd (int v[], int n) {

	int c = 0, menor = n, i = 0;

	c = n;
	
	while (i < n)
	{
		/*if(menor < v[i])
		{
			menor = menor;
			c = c;
		}
		else
		{
			menor = v[i];
			c = i;
		}*/

		menor = menor < v[i] ? menor : v[i];
		c = menor < v[i] ? c : i;
		
		printf("menor: %d | c: %d | i: %d\n", menor, c, i);
		i++;
	}

	return c;

}


int main () {

	int v[10], i = 0, r = 0, n = 10;

	while(i < n)
	{
		scanf("%d",&v[i]);
		i++;
	}
	printf("\n");

	r = minInd(v,n);

	printf("r: %d\n",r);
	return 0;

}
