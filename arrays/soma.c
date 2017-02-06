#include<stdio.h>

int main () {

	int n, total = 0;
	while (n != 0) {
		scanf("%d",&n);
		total += n;
	}

	printf("total: %d\n",total);

}
