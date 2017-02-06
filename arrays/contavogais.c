#include<stdio.h>

int contaVogais (char s[]) {
	
	int i = 0, c = 0;

	while (s[i] != '\0')
	{
		if (s[i] == 'a')
			c++;
		i++;
	}

	return c;

}

int main () {

	int n;

 	char s[100];

	scanf("%s",s);

	n = contaVogais(s);

	printf("n: %d\n",n);

}
