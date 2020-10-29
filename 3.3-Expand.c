#include <stdio.h>

#define SIZE 1000

void expand(char s1[], char s2[]);

main()
{
	char t[SIZE] = "a-z";
	char s[SIZE];
	printf("%s\n", t);
	expand(t, s);
	printf("%s\n", s);
	char t1[SIZE] = "a-z0-9A-Z";
	char t2[SIZE];
	printf("%s\n", t1);
	expand(t1, t2);
	printf("%s\n", t2);
}

void expand(char s1[], char s2[])
{
	int i, j, temp;
	for (i = 0, j = 0; 1==1; ++i, ++j){
		if (s1[i] == '-' && i > 0)
			for (temp = s1[i-1]+1; temp < s1[i+1]; temp++){
				if (temp == s1[i+1]-1){
					s2[j] = temp;
				}
				else
					s2[j++] = temp;
			}
		else
			s2[j] = s1[i];

		if (s1[i] == '\0'){
			s2[++j] = '\0';
			break;
		}
	}
}
