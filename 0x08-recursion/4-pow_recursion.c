#include "main.h"

/**
 * _pow_recursion - return the value of `a` raised to power of `b`
 * @a: number value
 * @b: number power
 * Return: a to power of b
 */

int _pow_recursion(int a, int b)
{
	if (b < 0)
		return (-1);
	else if (b == 0)
		return (1);
	else if (b == 1)
		return (a);

	return (a * _pow_recursion(a, b - 1));
}
