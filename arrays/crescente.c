#include<stdio.h>


int crescente(int a[], int i, int j) {

	int r = 0, c = i;

	while (c < j)
	{
		if (a[c] <= a[c+1])
			r = 1;
		else
			{
				r = 0;
				break;
			}
		printf("c %d | a[c] %d | c+1 %d | a[c+1] %d | i %d j %d\n",c, c+1, a[c], a[c+1], i, j);
		c++;
	}

	return r;

}


int main () {

	int i, j, r;
	int a[100] = {1,2,3,4,5,2,1,2};

	scanf("%d",&i);

	scanf("%d",&j);

	r = crescente (a,i,j);

	printf("r: %d\n",r);

	return 0;

}
