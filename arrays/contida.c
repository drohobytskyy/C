#include<stdio.h>


int contida (char a[], char b[]) {

	int contida = 0, i, j;

	while (a[i] != '\0')
	{
		while (b[j] != '\0')
		{
			if (b[j] == a[i])
			{
				contida = 1;
				break;
			}
			else
			{
				contida = 0;
				j++;
			}
		}
		if (contida)
		{
			j = 0;
			i++;
		}
		else
			break;
	}

	return contida;
}


int main () {

	int c;

	char a[100],  b[100];

	scanf("%s",a);
	scanf("%s",b);

	c = contida (a,b);

	printf("contida: %d\n", c);
}
