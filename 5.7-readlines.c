#include <stdio.h>
#include <string.h>

#define MAXL 10000
// Max contents of unique pointer
#define MAXCONTENT 100000

int getline1(char *s, int lim, int start);
void writelines1(char *lineptr[], int nlines);

main()
{
		char *s[MAXL];
		char line[MAXL];
		getline1(line, MAXCONTENT, 0);
		s[0] = line;
		writelines1(s, 1);
		getline1(line, MAXCONTENT, strlen(line));
		s[1] = line;
		writelines1(s, 2);
		printf("TESTING\n");
		printf("%s\n", s[0]);
		printf("%s\n", s[1]);
}

/* Modified to write where we point to,
 * so it can be used to store values
 * not using alloc
 * usage: getline1(storage, CHARLIMIT, where_to_start)
 * */
int
getline1(char *s, int lim, int start)
{
	int c, i;

	s += start;

	if (*s == '\0')
		*s = ' ';

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
		*s++ = c;

	if (c == '\n')
		*s++ = c;

	*s = '\0';

	return i;
}

/* writelines:  write output lines */
void writelines1(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
