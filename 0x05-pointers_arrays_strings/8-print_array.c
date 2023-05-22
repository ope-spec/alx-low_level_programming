#include "main.h"
#include <stdio.h>

/**
 * print_array - prints `n` elements of an array of integers
 * @arr: pointer to an array of integers
 * @n: number of elements to be printed
 * Description: The numbers will be separated by a comma and a space.
 * The numbers will be displayed in the same order as they are stored in the array.
 */

void print_array(int *arr, int n)
{
	int i;

	i = 0;
	for (n--; n >= 0; n--, i++)
	{
		printf("%d", arr[i]);
		if (n > 0)
		{
			printf(", ");
		}
	}
	printf("\n");
}
