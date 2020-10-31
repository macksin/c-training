#include <stdio.h>

void swap(int *px, int *py);

main()
{
	int x, y;
	x = 5;
	y = 10;

	printf(" %d %d\n", x, y);

	swap(&x, &y);
	printf(" %d %d\n", x, y);
}

void
swap(int *px, int *py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}
