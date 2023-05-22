#include "main.h"

/**
 * print_triangle - print a triangle aligned right, using '#'
 * @size: Size of triangle
 */

void print_triangle(int size)
{
	int ch, i, j;

	ch = 0;
	i = size - 1;
	while (ch < size)
	{
		i = size - 1 - ch;
		j = ch + 1;
		while (i > 0)
		{
			_putchar(' ');
			i--;
		}
		while (j > 0)
		{
			_putchar('#');
			j--;
		}
		_putchar('\n');
		ch++;
	}

	if (size <= 0)
		_putchar('\n');
}
