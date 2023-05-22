#include "main.h"

/**
 * _isupper - function that checks whether a character is uppercase
 * @ch: int type number
 * Return: 1 if uppercase, else 0
 */
int _isupper(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);

	return (0);
}
