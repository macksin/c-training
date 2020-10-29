#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

int any(char s1[], char s2[]);

main()
{
	char palavra[] = "sadfhjasdlfkajshdfwie cn";
	char dicionario[] = "p";
	int i;
	printf("%s\n", palavra);
	printf("%d\n", any(palavra, dicionario));
}

int any(char s1[], char s2[])
{
	int pos, i, k;
	pos = -1;
	for (i = 0; s1[i] != '\0'; i++)
		for (k = 0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k]){
				if (pos > -1){
					pos = MIN(pos, i);
				}else{
					pos = i;
				}
			}
	return pos;
}
