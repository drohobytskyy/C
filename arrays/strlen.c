#include<stdio.h>


int strlength (char str[]){

	int c;

	for (c=0; str[c]!=0; c++);
	
	return c;

}

int main () {

	int n;
	char str [100];

	scanf("%s",str);

	n = strlength (str);

	printf("lenght str: %d\n",n);

	return 0;
}
