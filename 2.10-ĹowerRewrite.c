#include <stdio.h>

main()
{
	char test = 'A';
	printf(" %c\n", test);
	printf(" %c\n", lower(test));
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
