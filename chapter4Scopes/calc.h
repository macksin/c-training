#define NUMBER '0'
#define ALPHA '1'

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
char variable;
int chvars[1000];
