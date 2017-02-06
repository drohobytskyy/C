#include<stdio.h>

int main () {

	int s = 0, m = 0, n, temp = 0, sm = 0;

	while (n != 0) {

		scanf("%d",&n);

		m = m >= n ? m : n;

		temp = s < m ? s : temp;

		sm = sm >= temp ? sm : temp;

		s = n;

	}
		
		printf("maior: %d | segundo maior: %d \n",m, sm);

}
