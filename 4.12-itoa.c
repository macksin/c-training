#include <stdio.h>

void itoa(int i);

char s[100];
int sp = 0;

main()
{
	int i = 1445;

	printf("Number %d.\n", i);

	itoa(i);
	
	printf("Number %s.\n", s);
}

void itoa(int i)
{
	if (i/10){
		itoa(i/10);
	}

	s[sp++] = i%10 + '0';	
	
}
