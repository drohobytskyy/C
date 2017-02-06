#include<stdio.h>
#include<string.h>


void strnoV (char s[]) {

	int c = 0, i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == 'a' ||
			s[i] == 'e' ||
			s[i] == 'i' ||
			s[i] == 'o' ||
			s[i] == 'u')
		{
			i++;
		}
		else
		{
			s[c] = s[i];
			i++; c++;
		}
	}

	s[c] = '\0';	

}

int main() {

	char s[100];
	
	scanf("%s",s);
	
	strnoV(s);

	printf("new string: %s\n",s);

}
