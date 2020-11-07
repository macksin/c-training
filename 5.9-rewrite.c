#include <stdio.h>


// Days
static char daytab[2][13] =  {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int
day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

int
day_of_year_mine(int year, int month, int day)
{
	int i, leap;
	char *p;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = &daytab[leap][1];
	for (i = 1; i < month; i++)
		day += *p++;
	return day;
}

main()
{
	printf("January has: %d days.\n", daytab[0][1]);
	int day, month, year;
	day = 11;
	month = 2;
	year = 1991;
	printf("The date: %d/%d/%d is the %d day of the year.\n",
			day,
			month,
			year,
			day_of_year(year, month, day));
	printf("The date: %d/%d/%d is the %d day of the year.\n",
			day,
			month,
			year,
			day_of_year_mine(year, month, day));
}
