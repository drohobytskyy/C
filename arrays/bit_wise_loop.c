#include<stdio.h>

int while_loop(int x, int y, int n);

int main () {

	int x = 4, y = 2, n = 3, z;

	z = while_loop(x,y,n);

	z = y & x;

	printf("%d\n",z);

	return 0;

}

int while_loop(int x, int y, int n) {

	while ((n > 0) & (y < n))
	{
		x += n;
		y *= n;
		n--;
	}

	return x;

}
