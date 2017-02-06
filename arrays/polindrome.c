#include<stdio.h>
#include<string.h>

int polindrome (char s[]) {

	int i = 0, j = 0, v = 0;
	i = strlen (s) - 1;

	while (i >= 0)
	{
		if (s[i] == s[j])
		{
			v = 1;
		}
		else
		{
			v = 0;
			break;
		}

		i--; j++;
	}

	return v;

}

int main () {

	int p;

	char s[100];

	scanf("%s",s);

	p = polindrome (s);

	printf("v: %d\n",p);

}
