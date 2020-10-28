#include <stdio.h>
#include <limits.h>

/*
 * Determine the ranges of variables types. 
**/

#define WHILE(X) 	size=0; X = 0;\
		while (1){ \
		if (size==(X)){\
			size++;\
			(X)++;\
		}\
		else{\
			break;\
		}\
	}

#define WHIL(i, vartype1, vartype2) 	i=1;\
	while(1){\
		if (i == (vartype1 vartype2) (i<<1|1)){\
			break;\
		}else{\
			i = i<<1|1;\
		}\
	}


main()
{

	unsigned long int size;

	unsigned char charsize;
	WHILE(charsize);
	printf("unsigned char CALC:\t %d\n", size-1);
	printf("unsigned char HEADER:\t %d\n", UCHAR_MAX);
	
	signed char scharsize;
	WHILE(scharsize);
	printf("signed char CALC:\t %d\n", size-1);
	printf("signed char HEADER:\t %d\n", SCHAR_MAX);

	unsigned short shortinho;
	WHILE(shortinho);
	printf("unsigned short CALC:\t %d\n", size-1);
	printf("unsigned short HEADER:\t %d\n", USHRT_MAX);

	signed short xshortinho;
	WHILE(xshortinho);
	printf("signed short CALC:\t %d\n", size-1);
	printf("signed short HEADER:\t %d\n", SHRT_MAX);

	unsigned long test;
	WHIL(test, unsigned, long);
	printf("unsigned long CALC:\t %lu\n", test);
	printf("unsigned long HEADER:\t %lu\n", ULONG_MAX);

	signed long var1;
	var1=0;
	while(1){
		if ((var1<<1|1)<=0 ){
			break;
		}else{
			var1 = var1<<1|1;
		}
	}
	printf("signed long CALC:\t %ld\n", var1);
	printf("signed long HEADER:\t %ld\n", LONG_MAX);
}


