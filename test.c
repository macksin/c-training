#include <stdio.h>

main()
{
	unsigned short i;
	
	for (i=0; i<10; ++i)	
		printf(" %d", i);
	printf("\n");

	for (i=0; i<10; i++)	
		printf(" %d", i);
	printf("\n");
}
