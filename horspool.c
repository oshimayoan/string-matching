#include <stdio.h>
#include <string.h>

#define ASIZE 1000

void OUTPUT(int idx)
{
	printf("Found at index %d.\n", idx);
}

void preBmBc(char *x, int m, int bmBc[])
{
	int i;

	for(i = 0; i < ASIZE; ++i)
		bmBc[i] = m;
	for(i = 0; i < m -1; ++i)
		bmBc[x[i]] = m - i - 1;
}

int HORSPOOL(char *x, int m, char *y, int n)
{
	int i, j, bmBc[ASIZE];
	char c;
	int count = 0;

	/* Preprocessing */
	preBmBc(x, m, bmBc);

	/* Searching */
	j = 0;
	while (j <= n - m) {
		for(i = 0; i < j; ++i)
			printf(" ");
		printf("%s\n", x);
		c = y[j + m - 1];
		if (x[m - 1] == c && memcmp(x, y + j, m - 1) == 0){
			OUTPUT(j);
			count++;
		}
		j += bmBc[c];
	}

	return count;
}

int main()
{
	// char x[] = "ello";
	// char y[] = "Hello world! Hello world! Hello world!";
	char x[] = "abc";
	char y[] = "ajfisafjsjnfricjmfiswhcismhcgiabcsfisrj,fiserhfisefieshabcabcjeiofsjifwabckabcjdfsjfsrm";
	int r;

	printf("%s\n", y);

	// Do Horspool search
	r = HORSPOOL(x, strlen(x), y, strlen(y));
	if(r < 1)
		printf("String pattern not found.\n");

	printf("\n");
	return 0;
}