#include <stdio.h>
#include <limits.h>

unsigned rr(unsigned x, unsigned n);

main()
{
		unsigned int x = 5;
		unsigned int n = 2;
		printf(" %u\n", rr(x, n));
}

unsigned rr(unsigned x, unsigned n)
{
		return (x << (CHAR_BIT*sizeof(x)-n)) | (x >> n);
}
