#include<stdio.h>


int nMenosFreq (int v[], int n) {

	int i = 0, j = 0, menor = n, c = 0, mf = 0;

	if (v[i] != v[i+1])
		return v[i];

	while(i<n-1)
	{
		j = i;
		while(v[j] == v[i])
		{
			c++;
			j++;
		}
		if(menor < c)
		{
			menor = menor;
		}
		else
		{
			menor = c;
			mf = v[i];
		}
		printf("c: %d | i: %d | j: %d\n",c,i, j);
		i+=c;
		c = 0;
	}

	return mf;

}


int main () {

	int v[100] = {1,1,1,2,2,2,3,3,3,4,4,5,5};
	int n, r;     
	scanf("%d",&n);
	r=nMenosFreq(v,n);
	printf("%d\n",r);
	return 0;

}
