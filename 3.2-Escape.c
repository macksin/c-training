#include <stdio.h>

#define SIZE 100

void escape(char s[], char t[]);
void unscape(char s[], char t[]);

main()
{
	char t[SIZE] = "TESTE 	 as 	Más CCCC Que 		sim";
	char s[SIZE];
	printf("%s\n", t);
	escape(s, t);
	printf("%s\n", s);
	unscape(t, s);
	printf("%s\n", t);
}

void escape(char s[], char t[])
{
	int i, j;
	for (i=0, j=0; t[i] != '\0'; ++i, ++j){
		switch (t[i]){
			case '\n':
				s[j++] = '\\';
				s[j] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j] = 't';
				break;
			default:
				s[j] = t[i];
				break;
		}
	}
}

void unscape(char s[], char t[])
{
	int i, j;
	for (i=0, j=0; t[i] != '\0'; ++i, ++j){
		switch (t[i]){
			case '\\':
				if (t[i+1] == 'n')
					s[j] = '\n';
				else if (t[i+1] == 't')
					s[j] = '\t';
				i++;
				break;
			default:
				s[j] = t[i];
				break;
		}
	}
}
