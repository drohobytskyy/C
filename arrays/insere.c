#include<stdio.h>


void insere(int v[], int n, int x) {

	/*int i = 0, temp [n];
	v[n] = x;
	i = n;

	while(v[i] < v[i-1])
	{
		temp[i] = v[i-1];
		v[i-1] = v[i];
		v[i] = temp[i];
		i--;
	}*/

	int i = 0;

	for(i = n; i > 0 && v[i-1] > x; i--)
	{
		v[i] = v[i-1];
	}

	v[i] = x;
	
}


int main () {

	int n=5, i = 0, x, y;
	int v[10];
	
	while (i<n)
	{
		scanf("%d",&x);
		v[i] = x;
		i++;
	}

	printf("add a number: ");
	scanf("%d",&y);
	insere (v,n,y);

	i = 0;

	while(i<n+1)
	{
		printf("%d\n",v[i]);
		i++;
	}
	
}
