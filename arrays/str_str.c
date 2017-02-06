#include<stdio.h>

char *string_str(char s1[], char s2[]){

	int i, j, c = 0, r = 0;

	if (s1 == NULL || s2 == NULL)
		return NULL;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == s2[c])
		{
			j = i;

			while (s2[c] != '\0')
			{
				if (s1[i] == s2[c])
				{
					i++;
					c++;
					r = 1;
				}
				else
				{
					r = 0;
					break;
				}
			}

			c = 0;
		}
	}
	
	if (r)
		return s1+j;
	else
		return NULL;

}

int main () {

	char s1[100], s2[100], *temp;;
	
	scanf ("%s",s1);
	scanf ("%s",s2);

	temp = string_str(s1,s2);

	printf("%s\n",temp);

	return 0;
}
