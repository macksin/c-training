#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.h"

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
