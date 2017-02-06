#include<stdio.h>

int main () {

	int n, soma=0, total=-1;
	float media;
	while (n != 0) {
		
		total ++;
		scanf("%d",&n);
		soma += n;

	}

	media = (float)soma/(float)total;

	printf("media: %f \n",media);

}
