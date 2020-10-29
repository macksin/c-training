#include <stdio.h>
#include <limits.h>

#define SIZE 1000

int strrindex(char s[], char t[]);

main()
{
	char s[SIZE] = "monmonkey monkey";
	char t[SIZE] = "monkey";
	int i;
	printf("%s\n", s);
	for (i=0; i<strrindex(s, t); i++)
		printf(" ");
	printf("%s\n", t);
	printf(" %d\n", strrindex(s, t));
}

int strrindex(char s[], char t[])
{
	int i, j, k, temp;

	temp = -1;
	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; k++, j++)
			;
		if (t[k] == '\0' && k > 0)
			temp = i;
	}
	
	return temp;
}
