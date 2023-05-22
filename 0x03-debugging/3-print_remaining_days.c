#include <stdio.h>
#include "main.h"

/**
 * print_remaining_days - calculates and prints the number of days
 * left in the year, considering leap years
 * @m: month in number format
 * @d: day of month
 * @year: year
 * Return: void
 */

void print_remaining_days(int m, int d, int year)
{
	if ((year % 4 == 0) && (year % 400 == 0 || year % 100 != 0))
	{
		if (m >= 3 && d >= 60)
		{
			d++;
		}

		printf("Day of the year: %d\n", d);
		printf("Remaining days: %d\n", 366 - d);
	}
	else
	{
		if (m == 2 && d == 60)
		{
			printf("Invalid date: %02d/%02d/%04d\n", m, d - 31, year);
		}
		else
		{
			printf("Day of the year: %d\n", d);
			printf("Remaining days: %d\n", 365 - d);
		}
	}
}
