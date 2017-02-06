#include<stdio.h>
#include<string.h>

int maiorSufixo(char s1[], char s2[]){

	int i, j, c = 0;
	
	i = strlen (s1) - 1;
	j = strlen (s2) - 1;

	while (s1[i] == s2[j]  && i >= 0 && j >= 0)
	{
		i--;
		j--;
		c++;
	}

	return c;

}


int main () {

	int n;

	char s1[100], s2[100];

	scanf("%s",s1);
	scanf("%s",s2);

	n = maiorSufixo(s1,s2);

	printf("n: %d\n",n);

}
