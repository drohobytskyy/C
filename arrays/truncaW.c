#include<stdio.h>

void truncaW (char t[], int n) {

	int l, e, dentro = 1, comp = 1;

	while (t[l] != '\0')
	{
		if ((dentro != 1) || (dentro == 1 && comp <= n))
		{
			t[e] = t[l];
			e++;
		}
		if (t[l] == ' ')
		{
			t[e] = ' ';
			dentro = 0;
			comp = 1;
			e++;
		}
		else
		{
			dentro = 1;
			comp++;
		}
		l++;
	}
	t[e] = '\0';
}

int main () {

	int n;
	char t[1024];

	fgets(t,1025,stdin);
	scanf("%d,",&n);

	truncaW(t,n);

	printf("new string: %s\n",t);

}
