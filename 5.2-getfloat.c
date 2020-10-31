#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getint(float *pn);

main()
{
	float z;
	getint(&z);
	printf("--> %f\n", z);
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
getint(float *pn)
{
	int c, sign, j;
	float o;

	while(isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c!= '-'){
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-' || c == ' ')
		c = getch();
	printf(" before loop: %c\n", c);
	for (*pn = 0, j = 0; isdigit(c) || c == '.'; c = getch()){
		if (c == '.')
			j = 1;
		else{
			*pn = 10 * *pn + (c - '0');
			j *= 10;
		}
		printf(" %c ", c);
	}
	printf("\n");

	*pn *= (float) sign;
	*pn = (j > 0) ? *pn / j : *pn;


	if (c != EOF)
		ungetch(c);
	return c;
}
