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
   unsigned long int printbit = 1ul << 63;
	char c = '0';

	while (!(printbit & n) && printbit != 0)
		printbit = printbit >> 1;

	if (printbit == 0)
		write(1, &c, 1);

	while (printbit)
	{
		if (printbit & n)
			c = '1';
		else
			c = '0';
		write(1, &c, 1);
		printbit = printbit >> 1;
	}
}