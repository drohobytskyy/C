#include<stdio.h>

int comunsOrd (int a[], int na, int b[], int nb) {

	int c = 0, i = 0, j = 0;

	while (i < na)
	{

		j = 0;

		while(j < nb)
		{

			if(a[i] == b[j])
			{
				c++;
				break;
			}
			j++;

		}
		i++;
	}

	return c;
}


int main () {

	int a[10], b[10],r = 0, i = 0, j = 0, na = 9, nb = 7;

	while(i < na)
	{
		scanf("%d",&a[i]);
		i++;
	}

	printf("\n");

	while(j < nb)
	{	
		scanf("%d",&b[j]);
		j++;
	}

	r = comunsOrd(a,na,b,nb);

	printf("r: %d\n",r);


	return 0;

}
