#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the number
 * @index: index of the bit to be cleared
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	/* check if index is greater than the number of bits in unsigned long int */
	if (index >= (sizeof(unsigned long int) * 8))
    {
        return (-1);
    }

	/* clear bit at the given index by ANDing with complement of bit shifted left */
	*n &= ~(1UL << index);

	return (1);
}





