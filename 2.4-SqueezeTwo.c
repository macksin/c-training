#include <stdio.h>

void squeezetwo(char s1[], char s2[]);

main()
{
	char palavra[] = "rayssa peixoto mendes";
	char dicionario[] = "iey ";
	int i;
	printf("%s\n", palavra);
	squeezetwo(palavra, dicionario);
	printf("%s\n", palavra);
	
}

void squeezetwo(char s1[], char s2[])
{
	unsigned short i, j, k, mark;
	
	for (i = j = 0; s1[i] != '\0'; i++){
		mark = 0;
		for (k = 0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k])
				mark++;
		if (mark==0)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
	
}
