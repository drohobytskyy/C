#include<stdio.h>

int main () {

	int n, c, k, u = 0;

	scanf("%d",&n);

	for (c = 31; c >= 0; c--) {
	
		k = n >> c;

		if (k & 1) {

			printf("1");
			u++;

		}

		else

		{
			
			printf("0");

		}

	}

	printf("\n");

	printf("uns: %d\n",u);

}
