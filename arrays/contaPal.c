#include<stdio.h>

int contapal (char s[]) {

	int i = 0, c = 1;

	while (s[i] != '\0')
	{
		if (s[i] == ' ' && s[i+1] != ' ' && s[i+1] != '\0')
			c++;
		i++;
	}

	return c;
}

int main () {

	int n;

	char s[100];

	fgets(s,1024,stdin);

	n = contapal (s);

	printf ("n: %d\n",n);

}
