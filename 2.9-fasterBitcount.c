#include <stdio.h>

int bitcoint(unsigned x);

main()
{
		unsigned a = 1;
		unsigned b = 923;

		while (b>0){
				printf("Number is %u\n", b &= (b-1));
		}
		b = 923;
		printf("Number of 1's %d\n", bitcoint(b));
}

int bitcoint(unsigned x)
{
		int b;
		
		for (b = 0; x != 0; x &= (x-1))
				b++;
		return b;
}
