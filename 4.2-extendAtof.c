#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double atoff(char s[]);

main()
{
	char line[100] = "12545.134";
	double i;

	printf(" %s\n", line);
	printf(" %f\n", atof(line));

	char line2[100] = "132.3e-2";
	
	printf(" %s\n", line2);
	printf(" %f\n", atoff(line2));

	char line3[100] = "89.1234e3";
	
	printf(" %s\n", line3);
	printf(" %f\n", atoff(line3));
}

double
atoff(char s[])
{
	char temp[100];
	char temp2[100];
	int i, p, power, j;
	double sum;

	for (i = 0, p = 0; isdigit(s[i]) || s[i] == '.'; i++, p++)
		temp[i] = s[i];

	sum = atof(temp); /* Before "E" */

	/* E process and sign process */
	if (s[p] == 'e' || s[p] == 'E')
		p++;

	if (s[p] == '-'){
		power = -1;
		p++;
	}
	else if (s[p] == '+'){
		power = 1;
		p++;
	}
	else{
		power = 1;	
	}

	/* After E */
	for (i = p, j = 0; isdigit(s[i]); i++, j++)
		temp2[j] = s[i];
	power = atoi(temp2) * power;	

	return sum*pow(10, power);

}

