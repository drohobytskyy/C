#include<stdio.h>


int nMaisFreq (int v[] ,int n){

	int maior = 0, c = 0, i = 0, j = 0, maisFreq = 0;

	while (i < n)
	{
		j = i;
		while (v[j] == v[i])
		{
			j++;
			c++;
		}

		printf("maisFreq: %d | j: %d | c: %d\n",maisFreq, j, c);
		if (maisFreq > c)
		{
			maisFreq = maisFreq;
		}
		else
		{
			maisFreq = c;
			maior = v[i];
		}

		i+=c;
		c = 0;
	}

	return maior;

}


int main () {

	int n = 5, i = 0, r = 0;
	int v[10];
	while (i < n)
	{
		scanf("%d",&v[i]);
		i++;
	}
	printf("\n");

	r = nMaisFreq(v,n);

	printf("r: %d\n",r);

	return 0;

}
