#include<stdio.h>


int iguaisCons (char s[]) {

	int i = 0, j = 0, maior = 0, c = 1, temp = 0;

	while (s[i] != '\0')
	{
		j = i;
		while (s[j] != '\0')
		{
				if (s[j] != s[j+1])
					break;
				c++;
				j++;
		}
		
		temp = c;
		c = 1;
		i++;

		if (maior > temp)
			maior = maior;
		else
			maior = temp;
	}

	return maior;
}


int main () {
	
	int n;

	char s[100];

	scanf("%s",s);

	n = iguaisCons(s);

	printf("n: %d\n",n);

}
