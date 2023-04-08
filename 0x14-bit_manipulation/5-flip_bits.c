#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another.
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int i = n ^ m;
unsigned int count = 0;

while (i != NULL)
{
count += i & 1;
i >>= 1;
}

return (count);
}
