#include<stdio.h>


int string_cmpr(char s1[], char s2[]) {

	int c = 0;

	while (s1[c] == s2[c])
	{

		if (s1[c] == '\0')
			break;
		c++;
	}

	if (s1[c] == s2[c])
		return 0;
	else if (s1[c] == '\0')
		return -1;
	else if (s2[c] == '\0')
		return 1;
	else return s1[c] < s2[c] ? -1 : 1;

}


int main () {

	
	int i;
	char s1[100],s2[100];
		
	scanf("%s",s1);
	scanf("%s",s2);

	i = string_cmpr(s1,s2);
	
	printf("%d\n",i);
	return i;
	printf("\n");

}
