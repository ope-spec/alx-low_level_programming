#include "main.h"

/**
 * _isdigit - Check for digits (0 through 9)
 * @ch: int type param
 * Return: 1 if digit, else 0
 */

int _isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}
