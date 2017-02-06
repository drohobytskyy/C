#include<stdio.h>


int difCons(char s[]){

	int maior = 0, temp = 0, i = 0, j = 0, c = 0;

	while (s[i] != '\0')
	{
		j = i;
		while (s[j] != '\0')
		{
			if(s[j] == s[j+1])
				break;
			c++;
			j++;

			printf("c: %d | j: %d\n",c,j); 
		}
		
		temp = c;
		c = 0;

		if (maior > temp)
			maior = maior;
		else
			maior = temp;
		i++;
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
