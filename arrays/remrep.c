#include<stdio.h>

int remrep (char s[]) {

	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		while (s[i] == s[i+1])
			i++;

		s[j] = s[i];
		i++;
		j++;
	}

	s[j] = '\0';

	return j;
}


int main () {

	int n;

	char s[100];

	scanf("%s",s);

	n = remrep(s);

	printf("n: %d | s: %s\n",n,s);
}
