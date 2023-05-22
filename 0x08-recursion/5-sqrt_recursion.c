#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer number
 * Return: natural square root if found, -1 otherwise
 */
int _sqrt_recursion(int n)
{
	int sqrt_fun(int n, int sq);

	int sq = 1;

	return (sqrt_fun(n, sq));
}

/**
 * sqrt_fun - helper function for solving _sqrt_recursion
 * @sq: number to determine if it has a square root
 * @n: integer number
 * Return: square root if it has a natural square root, or -1 if none found
 */

int sqrt_fun(int n, int sq)
{
	if (n == sq * sq)
	{
		return (sq);
	}
	else if (sq < n)
	{
		return (sqrt_fun(n, ++sq));
	}
	else
	{
		return (-1);
	}
}
