#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int c);

main()
{
	int i;
	while((i = getch()) != EOF){
		putchar(i);
	}
	printf("\n");

	printf("***********");

	int j = 100;
	int s = &j;
	
	printf("Memory Location: %d\n", s);	
}

int 
getch(void)
{
	if (bufp > 0)
		return buf[--bufp];
	else
		return getchar();
}

void
ungetch(int c)
{
	if (buf >= BUFSIZE)
		printf("ERROR ungetch: end of buffer.\n");
	else
		buf[bufp++] = c;
}
