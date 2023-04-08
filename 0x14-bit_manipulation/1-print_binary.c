#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 *
 * @n - unsigned long int n
 *
 * Return: no return
 */
void print_binary(unsigned long int n)
{
   unsigned long int mask = 1;
	int printed = 0;

	mask <<= (sizeof(unsigned long int) * 8) - 1;

	while (mask > 0)
	{
		if ((n & mask) == 0 && printed == 0)
		{
			mask >>= 1;
			continue;
		}

		if ((n & mask) != 0)
		{
			_putchar('1');
			printed = 1;
		}
		else
		{
			_putchar('0');
			printed = 1;
		}

		mask >>= 1;
	}

	if (!printed)
		_putchar('0');
}