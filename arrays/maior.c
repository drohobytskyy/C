#include<stdio.h>

int main () {

	int m = 0, n;
	
	while (n != 0) {

		scanf("%d",&n);
		m = m >= n ? m : n;
	}

	printf("maior: %d \n", m);

}
