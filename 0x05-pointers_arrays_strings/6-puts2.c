#include "main.h"

/**
 * puts2 - print one char out of 2 of a string
 * @s: char array string type
 * Description: Print 1st char, then 3rd, then 5th, etc..
 */

void puts2(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (i % 2 == 0)
			_putchar(s[i]);
	}
	_putchar('\n');
}
