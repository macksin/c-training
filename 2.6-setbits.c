#include <stdio.h>
#include <math.h>

int setbits(int x, int p, int n, int y);

main()
{
		int num1 = 255;
		int num2 = 0;
		int answer = 476;
		int n = 4;
		int p = 3;
		//printf("Para limpar 4 bits precisamos do número: %d\n", bindec(4));
		answer = setbits(num1, p, n, num2);
		printf(" %d with n=%d bits from position=%d removed, EQ = %d\n", num1, n, p, answer);
}

int setbits(int x, int p, int n, int y)
{
		int a1, a2, a3, a4;
		a1 = x & ~(~(~0 << n) << (p+1-n));
		a2 = (y & ~(~0 << n)) << (p+1-n);
		a3 = a1 + a2;
		return a3;
}

