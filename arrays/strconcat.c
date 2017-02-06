#include<stdio.h>
#include<string.h>


char *strconcat(char s1[], char s2[]){

	int i, j, length;
	length = strlen (s1);

	for (i = length; s2[j] != '\0'; i++,j++)
	{
		s1[i] = s2[j]; 
	}

	s1[i] = '\0';

	return s1;

}

int main() {

	char s1[100], s2[100], *s3;

	scanf("%s",s1);
	scanf("%s",s2);

	s3 = strconcat (s1,s2);
	

	printf("String: %s\n",s3);

}
