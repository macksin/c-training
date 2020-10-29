#include <stdio.h>
#include <limits.h>

#define SIZE 1000

/*
 * reverse and string_length are from "https://www.programmingsimplified.com/c-program-reverse-string"
**/

void itoa(int n, char s[]);
void reverse(char *s);
int string_length(char*);

main()
{
	int n;

	char s[SIZE];
	n = -10;
	printf("%d\n", n);
	itoa(n, s);
	printf("%s\n", s);

	char x[SIZE];
	n = INT_MIN;
	n = -n;
	//n -= 1;
	printf("%d\n", n);
	itoa(n, x);
	printf("%s\n", x);
}

void itoa(int n, char s[])
{
	int i, sign, correct_int;
	
	if ((sign = n) < 0){
		if (n == INT_MIN){
			correct_int = 1;
			n = n+1;
			n = -n;
		}
		else
			n = -n;
	}
	i = 0;
	do {
		if (correct_int == 1){
			s[i++] = (n % 10 + correct_int) + '0';
			correct_int = 0;
		}
		else
			s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char *s)
{
   int length, c;
   char *begin, *end, temp;
 
   length = string_length(s);
   begin  = s;
   end    = s;
 
   for (c = 0; c < length - 1; c++)
      end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

int string_length(char *pointer)
{
   int c = 0;
 
   while( *(pointer + c) != '\0' )
      c++;
 
   return c;
}
