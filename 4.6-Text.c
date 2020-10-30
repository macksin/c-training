#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define ALPHA '1' /* signal for alphanumeric */
int getop(char []);
void push(double);
double pop(void);
float chvars[26];
char variable;
/* reverse Polish calculator */
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
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i,c;
	
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	
	i = 0;
	if(!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
		return c;
	
	if(c == '-')
        	if(isdigit(c=getch()) || c == '.')
        		s[++i] = c;
        	else
        	{
        	    if(c != EOF)
        	        ungetch(c);
        	    return '-';
        	}

	if (isalpha(c)){
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (i == 1)
			variable = s[0];
		if(c != EOF)
			ungetch(c);
		return ALPHA;
	}
    
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
	        	;
	
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
	        	;
	
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
