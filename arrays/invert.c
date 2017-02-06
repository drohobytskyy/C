#include<stdio.h>
#include<string.h>


void reverse (char s[]) {

	int c=0, i, length;

	length = strlen (s);
	char temp;
	i=length-1;

	while (c<length/2)
	{
		temp = s[i];
		s[i] = s[c];
		s[c] = temp;
		c++; i--;
	}

}


int main () {

	char s[100];
	
	scanf("%s",s);

	reverse(s);

	printf("%s\n",s);

}
