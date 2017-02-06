#include<stdio.h>

char charMaisFrequente(char s []) {

	int i=0, j=0, cont = 0, maior = 0;
	char c = s[i];

	while (s[i] != '\0')
	{
		while (s[j] != '\0')
		{
			if (s[i] == s[j])
			{
				cont++;
			}
			j++;

			printf("cont: %d\n",cont);
		}
		if (maior > cont)
		{
			printf("maior: %d | cont: %d\n",maior, cont);
			maior = maior;
		}
		else
		{
			maior = cont;
			c = s[i];
		}

		cont = 0;
		j=0;	
		i++;

	}
	printf("maior: %d | char: %c\n",maior, c);
	return c;

}

int main () {

	char s[100];
	char c;

	scanf("%s", s);

	c = charMaisFrequente (s);

	printf("%c\n",c);

}
