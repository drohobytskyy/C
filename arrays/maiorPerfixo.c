#include<stdio.h>

int maiorPerfixo (char s1[], char s2[]) {

	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}

	return i;
}

int main () {
	
	int n;
	char s1[100], s2[100];

	scanf ("%s",s1);
	scanf ("%s",s2);

	n = maiorPerfixo(s1,s2);

	printf("n: %d\n",n);

}
