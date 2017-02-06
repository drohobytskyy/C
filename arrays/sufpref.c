#include<stdio.h>
#include<string.h>

int sufpref (char s1[], char s2[]) {

	int i, j = 0, c = 0;

	i = strlen (s1) - 1;

	while (s1[i] == s2[j] && i >= 0 && s2[j] != '\0')
	{
		c++;
		i--;
		j++;
	}

	return c;

}

int main () {

	int n;

	char s1[100], s2 [100];

	scanf("%s",s1);
	scanf("%s",s2);

	n = sufpref (s1,s2);

	printf("n: %d\n",n);

}
