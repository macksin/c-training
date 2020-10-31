#include <stdio.h>
#include <string.h>

#define swap(t, x, y) \
	x = x + y;    \
	y = x - y;    \
	x = x - y;

main()
{
	float a, b;

	a = 11.5f;
	b = 22.5f;

	printf(" %f %f\n", a, b);

	swap(float, a, b);
	
	printf(" %f %f\n", a, b);
}
