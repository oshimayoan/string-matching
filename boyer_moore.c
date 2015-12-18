#include <stdio.h>
#include <string.h>

#define ASIZE 1000
#define XSIZE 1000
#define MAX(a,b) \
	({ __typeof__ (a) _a = (a); \
	   	__typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })

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

void suffixes(char *x, int m, int *suff)
{
	int f, g, i;
	suff[m - 1] = m;

	g = m - 1;
	for(i = m - 2; i >= 0; --i){
		if (i > g && suff[i + m - 1 - f] < i - g)
			suff[i] = suff[i + m - 1 - f];
		else{
			if (i < g)
				g = i;

			f = i;
			while (g >= 0 && x[g] == x[g + m - 1 - f])
				--g;

			suff[i] = f - g;
		}
	}
}

void preBmGs(char *x, int m, int bmGs[])
{
	int i, j, suff[XSIZE];

	suffixes(x, m, suff);

	for (i = 0; i < m; ++i)
		bmGs[i] = m;

	j = 0;
	for (i = m - 1; i >= -1; --i)
		if (i == -1 || suff[i] == i + 1)
			for (; j < m - 1 - i; ++j)
				if (bmGs[j] == m)
					bmGs[j] = m - 1 - i;
	
	for (i = 0; i <= m - 2; ++i)
		bmGs[m - 1 - suff[i]] = m - 1 - i;
}

int BM(char *x, int m, char *y, int n)
{
	int i, j, bmGs[XSIZE], bmBc[ASIZE];
	int count = 0;

	/* Preprocessing */
	preBmGs(x, m, bmGs);
	preBmBc(x, m, bmBc);

	/* Searching */
	j = 0;
	while (j <= n - m){
		for(i = 0; i < j; ++i)
			printf(" ");
		printf("%s\n", x);
		for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
		if (i < 0){
			OUTPUT(j);
			count++;
			j += bmGs[0];
		}
		else
			j += MAX(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
	}

	return count;
}

int main()
{
	char x[] = "ello";
	char y[] = "Hello world! Hello world! Hello world!";
	int r;

	printf("%s\n", y);

	// Do BM search
	r = BM(x, strlen(x), y, strlen(y));
	if(r < 1)
		printf("String pattern not found.\n");

	printf("\n");
	return 0;
}