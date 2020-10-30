#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

main()
{
    int type;
    double op2, op3;
	char s[MAXOP];


	printf("Operator + is sum.\n");
	printf("Operator * is multiplication.\n");
	printf("Operator - is minus.\n");
	printf("Operator / is division.\n");
	//printf("Operator /% is modulus.\n");
	printf("Operator $ is print the operands.\n");
	printf("Operator # is duplicate.\n");
	printf("Operator @ is swap.\n");
	printf("Operator ^ is pow.\n");
	printf("Operator = is variable assignment.\n");
	printf("Operator _ is bring back variable.\n");
	printf("Operator ~ is sin.\n");
	printf("Operator ! is exp.\n");

    while ((type = getop(s)) != EOF) {
	switch (type) {
	case NUMBER:
		push(atof(s));
		break;
	case ALPHA:
		printf("variable %c\n", variable);
		break;
	case '+':
		push(pop() + pop());
		break;
	case '*':
		push(pop() * pop());
		break;
	case '-':
		op2 = pop();
		push(pop() - op2);
		break; 
	case '/':
		op2 = pop();
		if (op2 != 0.0)
		    push(pop() / op2);
		else
		    printf("error: zero divisor\n");
		break;
	case '%':
		op2 = pop();
		push(fmod(pop(), op2));
		break;
	case '\n':
		printf("\t%.8g\n", pop());
		break;
	case '$': // print top two elements
		op2 = pop();
		op3 = pop();
		printf("operand(1)= %.8g operand(2)= %.8g\n", op3, op2);
		push(op3);
		push(op2);
		break;
	case '#': // duplicate
		op2 = pop();
		push(op2);
		push(op2);
		break;
	case '@': //swap
		op2 = pop();
		op3 = pop();
		push(op2);
		push(op3);
		break;
	case '^':
		op2 = pop();
		push(pow(pop(), op2));
		break;
	case '=':
		op2 = pop();
		printf("number: %f\n", op2);
		chvars[variable-97] = op2;
		break;
	case '_':
		push(chvars[variable-97]);
		break;
	case '~':
		push(sin(pop()));
		break;
	case '!':
		push(exp(pop()));
		break;
	default:
		printf("error: unknown command %s\n", s);
		break;
        }
    }
}
