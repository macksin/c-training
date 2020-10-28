#include <stdio.h>

/*
 * Hexadecimal to integer value. P.60.
**/

long htoi(char s[]);

main()
{
	char s[] = "3ab321";
	printf("This should print:\t\t3846945\n");
	printf("Answer:\t\t\t\t%ld\n", htoi(s));
}

long
htoi(char s[])
{
	int i;
	long n;
	n = 0;
	
	for (i = 0; (s[i] >= '0' && s[i] <= '9') ||
				(s[i] >= 'A' && s[i] <= 'F') ||
				(s[i] >= 'a' && s[i] <= 'f'); ++i){
		if (s[i] >= '0' && s[i] <= '9')
			n = 16*n + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = 16*n + (s[i] - 'A' + 10);
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = 16*n + (s[i] - 'a' + 10);
	}
	return n;
}
