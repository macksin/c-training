#include <stdio.h>

int invert(int x, int p, int n);

main()
{
		int x = 238;
		int p = 4;
		int n = 3;
		int answer = 0;
		answer = invert(x, p, n);
		printf("V= %d P= %d N= %d A= %d\n", x, p, n, answer);
}

int invert(int x, int p, int n)
{
		 return (x & ~(~(~0 << n) << (p+1-n))) | (~x & (~(~0 << n) << (p+1-n)));
}

