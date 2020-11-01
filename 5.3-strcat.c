#include <stdio.h>

void strcat(char *s, char *t);

main()
{
	char s[100] = "lexicon ";
	char t[100] = "aborigine";
	strcat(s, t);
	printf("\t%s\n", s);
}

void
strcat(char *s, char *t)
{
	while (*s++ != '\0')
		;

	*s--;
	while (*t != '\0')
		*s++ = *t++; 
}
