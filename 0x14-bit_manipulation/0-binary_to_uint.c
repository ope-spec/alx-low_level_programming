#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result;
	int length, base_two;

	if (!b)
		return (0);

	ui = 0;

	for (length = 0; b[length] != '\0'; length++)
		;

	for (length--, base_two = 1; length >= 0; lenth--, base_two *= 2)
	{
		if (b[lenth] != '0' && b[lenth] != '1')
		{
			return (0);
		}

		if (b[lenth] & 1)
		{
			ui += base_two;
		}
	}

	return (ui);
}