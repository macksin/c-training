#include <stdio.h>
#include <string.h>

main(int argc, char *argv[])
{
	if (argc != 2)
		printf("Usage: patter matching.");
	else
		printf("Argument: %s.\n", *++argv);
}
