#include <stdio.h>

#define MAXL 10000

int getline1(char s[], int lim);

main()
{
	//	char teste[MAXL];
	//	printf("==============\n");
	//	while (getline1(teste, MAXL) > 0)
	//		printf("\t%s\n", teste);
}

int
readlines(char *s[], int maxlines)
{
	int len, line[MAXL];


}

int
getline1(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
		*s++ = c;

	if (c == '\n')
		*s++ = c;

	*s = '\0';

	return i;
}
