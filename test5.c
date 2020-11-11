#include <stdio.h> 
#include <string.h>

int getop(char s[]);
  
main(int argc, char *argv[]) 
{
	int c;

	while(argc-- > 1){
		c = getop(*++argv);
		printf(" %s translates to %d\n", *argv, c);
	}
} 

int
getop(char s[])
{
	if (strcmp(s, "-") == 0)
		return 1;
	else if (strcmp(s, "+") == 0)
		return 2;
	else if (strcmp(s, "/") == 0)
		return 3;
	else
		return 4;
}
