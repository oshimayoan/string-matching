#include <stdio.h>
#include <string.h>

#define EOS '\0'

void OUTPUT(int idx)
{
	printf("Found at index %d.\n", idx);
}

int BF(char *x, int m, char *y, int n)
{
	char *yb;
	int count = 0;
	int i;

	/*Searching*/
	for(yb = y; *y != EOS; ++y){
		for(i = 0; i < y - yb; ++i)
			printf(" ");
		printf("%s\n", x);
		if(memcmp(x, y, m) == 0){
			OUTPUT(y - yb);
			count++;
		}
	}

	return count;
}

int main()
{
	char x[] = "ello";
	char y[] = "Hello world! Hello world! Hello world!";
	int r;

	printf("%s\n", y);

	// Do BF search
	r = BF(x, strlen(x), y, strlen(y));
	if(r < 1)
		printf("String pattern not found.\n");

	printf("\n");
	return 0;
}