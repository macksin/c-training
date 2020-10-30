#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include<ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char c[]);

main()
{
	char s[BUFSIZE] = "avioes do forro";
	int i;

	ungets(s);
	
	while ((i = getch()) != EOF)
		printf("%c", i);
	printf("\n");
	
}


char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char c[])
{
	int i;

	for (i = 0; c[i] != '\0'; i++)
		ungetch(c[i]);
}
