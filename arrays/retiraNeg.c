#include<stdio.h>


int retiraNeg (int v[], int n) {

		int i = 0, j = 0, r = 0;
		int temp [n];

		while (i < n-1)
		{
			j = 0;
			while (j < n-i-1)
			{
				if (v[j] < 0)
				{
					temp[j] = v[j+1];
					v[j+1] = v[j];
					v[j] = temp[j];
				}
				j++;
			}

			i++;
		}

		i = 0;

		while(v[i] >= 0)
		{
			i++;
			r++;
		}


		return r;
}


int main () {

	int a[100] = {1,4,3,-2,-1,2,3,5};
	int n,r;

	scanf("%d",&n);

	r = retiraNeg(a,n);

	int i = 0;

	while (a[i] > 0)
	{
		printf("r: %d | a[%d]: %d\n",r,i,a[i]);
		i++;
	}
	return 0;

}
