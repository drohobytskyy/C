#include<stdio.h>

int main () {

	int i = 0;

	while(i < 256)
	{
		printf("i: %d | c: %c\n",i, (char)i);
		i++;
	}

	return 0;
}
