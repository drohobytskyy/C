#include<stdio.h>


void somaAc (int v[], int ac[], int n) {

	int i = 0, temp = 0;

	while(i < n)
	{
		temp+= v[i];
		ac[i] = temp; 
		i++;
	}

}


int main () {

	int v[10], ac[10], n = 9, i = 0;

	while (i < n)
	{
		scanf("%d",&v[i]);
		i++;
	}

	printf("\n");

	somaAc(v,ac,n);	
	i = 0;

	while (i < n)
	{
		printf("%d\n",ac[i]);
		i++;
	}
	return 0;

}
