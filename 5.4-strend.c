#include <stdio.h>

int strend(char *s, char *t);

main()
{
	char s[100] = "abobora azul";
	char t[100] = "azul";
	char y[100] = "bzul";
	printf("s = %s\nt = %s\n", s, t);
	printf("\t%s\n", (strend(s, t) == 1) ? "contem" : "não contem");

	printf("s = %s\nt = %s\n", s, y);
	printf("\t%s\n", (strend(s, y) == 1) ? "contem" : "não contem");
}

int
strend(char *s, char *t)
{
	int ls, lt, ll;
	
	for(ls = 0; *s == '\0'; *s++)
		ls++;

	for(lt = 0; *t == '\0'; *t++)
		lt++;

	for(ll = 0; *s == *t; *s--, *t--, ll++)
		if (ll == lt)
			return 1;
		
	return 0;
}
