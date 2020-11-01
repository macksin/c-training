#include <stdio.h>

/*
 * Hexadecimal to integer value. P.60.
**/

long htoi(char *s);

main()
{
	char s[] = "3ab321";
	printf("This should print:\t\t3846945\n");
	printf("Answer:\t\t\t\t%ld\n", htoi(s));
}

long
htoi(char *s)
{
	int i;
	long n;
	n = 0;
	
	for (i = 0; (*s >= '0' && *s <= '9') ||
				(*s >= 'A' && *s <= 'F') ||
				(*s >= 'a' && *s <= 'f'); *s++){
		if (*s >= '0' && *s <= '9')
			n = 16*n + (*s - '0');
		else if (*s >= 'A' && *s <= 'F')
			n = 16*n + (*s - 'A' + 10);
		else if (*s >= 'a' && *s <= 'f')
			n = 16*n + (*s - 'a' + 10);
	}
	return n;
}
