#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch_ok(int x, int v[], int n);

#define N_ELEMENTS 100000

main()
{
	int a[N_ELEMENTS];
	int i;

	for (i = 0; i < N_ELEMENTS-1; ++i)
		a[i] = i;	

	clock_t timing;
	timing = clock();
	int answer = (binsearch(10, a, N_ELEMENTS)>-1);
	timing = clock() - timing;
	printf("Deu %s\n", (binsearch(10, a, N_ELEMENTS)>-1) ? "certo" : "errado" );
	printf("Com menos testes dentro do While %f seconds\n",(float) timing/CLOCKS_PER_SEC);

	timing = clock();
	int answer2 = (binsearch_ok(10, a, N_ELEMENTS)>-1);
	timing = clock() - timing;
	printf("Deu %s\n", (binsearch_ok(10, a, N_ELEMENTS)>-1) ? "certo" : "errado" );
	printf("Com a função original %f seconds\n",(float) timing/CLOCKS_PER_SEC);
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low+high)/2;
	while (low <= high || x != v[mid]){
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (x != v[mid]) ? -1 : mid;
}

int binsearch_ok(int x, int v[], int n) {
    int low, mid, high;
    
    low = 0;
    high = n - 1;
    while ( low <= high ) {
        mid = (low+high) / 2;
        if ( x < v[mid] )
            high = mid - 1;
        else if ( x > v[mid] )
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
