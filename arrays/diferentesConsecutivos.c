#include<stdio.h>


int difCons(char s[]){

	int maior = 0, temp = 0, i = 0, j = 0, c = 1;

	while (s[i] != '\0')
	{
		j = i;
		while(s[j] != '\0')
		{

			if (s[j] == s[j+1])
				break;
			c++;
			j++;
			printf("c: %d, j: %d, s[%c]\n", c, j, s[i]); 
		}
		
		i++;

		maior = maior > c ? maior : c;

		c = 1;
	}

	return maior;

}


int main () {

	char s[100];
	int n=0;

	scanf("%s",s);

	n = difCons(s);
	printf("n: %d\n",n);

}
