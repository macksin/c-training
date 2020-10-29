#include <stdio.h>
#include <limits.h>

#define SIZE 1000

/*
 * reverse and string_length are from "https://www.programmingsimplified.com/c-program-reverse-string"
**/

void itob(int n, char s[], int b);
void reverse(char *s);
int string_length(char*);

main()
{
	int n;

	char s[SIZE];
	n = -10;
	printf("%d\n", n);
	itob(n, s, 2);
	printf("%s\n", s);

	char s1[SIZE];
	n = -2834;
	printf("%d\n", n);
	itob(n, s1, 8);
	printf("%s\n", s1);


	char s2[SIZE];
	n = -2834;
	printf("%d\n", n);
	itob(n, s2, 16);
	printf("%s\n", s2);

	char x[SIZE];
	n = INT_MIN;
	printf("%d\n", n);
	itob(n, x, 16);
	printf("%s\n", x);


	char x1[SIZE];
	n = 2312523;
	printf("%d\n", n);
	itob(n, x1, 16);
	printf("%s\n", x1);
}

void itob(int n, char s[], int b)
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
			s[i++] = (((n + correct_int)% b ) > 9) ? ((n + correct_int) % b) + 'A' - 10 : ((n + correct_int) % b) + '0';
			correct_int = 0;
		}
		else
			s[i++] = ((n % b) > 9) ? (n % b) + 'A' - 10 : (n % b) + '0';
	} while ((n /= b) > 0);
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
