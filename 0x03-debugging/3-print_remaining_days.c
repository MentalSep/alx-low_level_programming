#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/
void print_remaining_days(int month, int day, int year)
{
	int total_days;

	if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0))
	{
		/*leap year*/
		total_days = 366;

		if (month > 2 && day >= 60)
		{
			day++;
		}
	}
	else
	{
		/*not a leap year*/
		total_days = 365;
		if (month == 2 && day == 60)
		{
			printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		}
	}
	printf("Day of the year: %d\n", day);
	printf("Remaining days: %d\n", total_days - day);
}
