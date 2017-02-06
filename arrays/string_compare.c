#include<stdio.h>

int string_compare(char s1[], char s2[]);

int main () {

	char s1[100], s2[100];

	int r = 0;

	scanf("%s",s1);
	scanf("%s",s2);

	r = string_compare(s1,s2);

	printf("res: %d\n",r);

	return 0;

}

int string_compare(char s1[], char s2[]) {

	int i, r = 0, t1 = 0, t2 = 0;

	for(i = 0; s1[i] != '\0'; i++)
	{
		t1 += (int)s1[i];
	}

	for(i = 0; s2[i] != '\0'; i++)
	{
		t2 += (int)s2[i];
	}

	if(t1 > t2)
		r = 1;
	else if(t1 < t2)
		r = -1;
	else
		r = 0;

	return r;

}
