#include<stdio.h>
#include<string.h>

char *stringcopy (char *dest, char source[]) {

	int c;
	while (source[c] != '\0')
	{
		*dest = source[c];
		dest++;
		c++;
	}

	*dest = '\0';
	return dest-c;
}


int main () {

	char source [100], dest [100], *d;

	scanf("%s",source);
	d = stringcopy (dest, source);


	printf("dest: %s\n",d);

}
