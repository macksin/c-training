#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getint(int *pn);

main()
{
	int z;
	getint(&z);
	printf(" %d\n", z);
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void)  /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int
getint(int *pn)
{
	int c, sign;

	while(isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c!= '-'){
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	while(isspace(c = getch()))
		;
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
