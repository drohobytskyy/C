#include<stdio.h>


void merge (int r[], int a[], int b[], int m, int n) {

	
	int i = 0, j = 0, k = 0;

	while(i < m && j < n)
	{
		if(a[i] <= b[j])
			r[k++] = a[i++];
		else
			r[k++] = b[j++];
	}

	while(i < m)
		r[k++] = a[i++];

	while(j < n)
		r[k++] = b[j++];

}


int main () {

	int r[100], a[50], b[50], c = 0, m = 3, n = 5;

	while(c < m)
	{
		scanf("%d",&a[c]);
		c++;
	}

	printf("\n");

	c = 0;
	while (c < n)
	{
		scanf("%d",&b[c]);
		c++;
	}

	printf("\n");

	merge(r,a,b,m,n);
	
	c = 0;
	printf("\n");
	while(c < m+n)
	{
		printf("%d\n",r[c]);
		c++;
	}

	
	return 0;

}
