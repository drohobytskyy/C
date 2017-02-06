#include<stdio.h>


int main ()
{

	int i,j,n,c=0, c1=0;
	int array [31];

	printf("Digite um numero na base 10: ");
	scanf("%d",&n);
	for(i=31; i>=0; i--)
	{
		j=n>>i;
		
		if (j & 1)
		{
			printf("1");
			array[i] = 1;
		}
		else
		{
		 	printf("0");
			array[i] = 0;
			c++;	
		}
	}
	
	
	printf("\n");

	
		for (i=0;i<=31;i++)
		{
			if(array[i]==0)
			{
				c1++;
				printf("%d i: %d\n",array[i],i);
			}
			else
			break;
		}
	

	printf("\n");
	printf("O valor de zeros é igual a: %d\n",c);
	
	printf("A quantidade de zeros no fim é: %d\n",c1);
}
