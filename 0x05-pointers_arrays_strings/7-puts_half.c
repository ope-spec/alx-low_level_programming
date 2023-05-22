#include "main.h"

/**
 * puts_half - print second half of a string
 * @s: char array string type
 * Description: If odd number of chars, print (length - 1) / 2
 */

void puts_half(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	i++;
	for (i /= 2; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
