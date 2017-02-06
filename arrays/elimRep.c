#include<stdio.h>


int elimRep (int v[], int n) {

	int i = 0, j = 0, k = 0;

	while (i < n)
	{
		j = i+1;
		while (j < n)
		{
				if(v[j] == v[i])
				{
					k = j;
					while(k < n)
					{
						v[k] = v[k+1];
						k++;
					}
					n--;
				}
				else
					j++;
		}
		i++;
	}

	return n;

}

int main () {

	int n = 9, i = 0, r = 0;
	int v[10];

	while (i < n)
	{
		scanf("%d",&v[i]);
		i++;
	}

	r = elimRep(v,n);
	printf("r: %d\n", r);
	
	i = 0;
	while(i < r)
	{
		printf("%d\n",v[i]);
		i++;
	}
	return 0;

}
