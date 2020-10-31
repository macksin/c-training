#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void shiftback(char s[]);

char s[100];
int sp = 0;

main()
{

	char s[] = "backpack";

	printf("Number %s.\n", s);

	reverse(s);
	printf("Number %s.\n", s);
}

void
reverse(char s[])
{
	char temp = s[0];
	void shiftback(char s[]);

	shiftback(s);

	int len = strlen(s);

	if (s[0] != '\0')
		reverse(s);

	s[len] = temp;
	
}

void
shiftback(char s[])
{
	int i;

	for (i = 0; (s[i] = s[i+1]) && s[i] != '\0'; i++)
		;
}

