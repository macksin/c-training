#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHA 97
#define VARIABLE 77
#define OPERATOR 22
#define NUMBER 2

int getop(char s[]);
void push(double);
double pop(void);

main(int argc, char *argv[])
{
	int op;
	argv++;
	while (argc-- > 1){
		op = getop(*argv);
		printf(" %s is mapped to %d\n", *argv, op);
		
		switch(op){
		case NUMBER:
			push(atof(*argv));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		}
		argv++;
	}
	printf(" RESULTADO: \t%.8g\n", pop());
}

int
getop(char s[])
{
	if (isalpha(s[0])){
		if (strlen(s) > 1)
			return ALPHA;
		else
			return VARIABLE;
	}
	else if (ispunct(s[0])){
		if (strlen(s) > 1)
			return NUMBER;
		return s[0];
	}
	else
		return NUMBER;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
