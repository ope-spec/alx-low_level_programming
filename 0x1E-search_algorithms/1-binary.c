#include "search_algos.h"

/**
 * binary_search - a function that searches for a value in
 * a sorted array of integers  using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If value is not present in array or
 * if array is NULL, function must return -1
 * function must return the index where value is located
 */

int binary_search(int *array, size_t size, int value)
{
	size_t sideA, sideB, i;

	if (array == NULL)
		return (-1);

	for (sideA = 0, sideB = size - 1; sideB >= sideA;)
	{
		printf("Searching in array: ");

		for (i = sideA; i < sideB; i++)
			printf("%d, ", array[i]);

		printf("%d\n", array[i]);

		i = sideA + (sideB - sideA) / 2;

		if (array[i] == value)
			return (i);
		else if (array[i] > value)
			sideB = i - 1;
		else
			sideA = i + 1;
	}

	return (-1);
}
