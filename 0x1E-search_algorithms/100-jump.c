#include "search_algos.h"

/**
 * jump_search -  searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: Return the first index where value is located
 * If value is not present in array or if array is NULL,
 * function must return -1
 */
int jump_search(int *array, size_t size, int value)
{
	int index, step, current, previous;

	if (array == NULL || size == 0)
		return (-1);

	step = (int)sqrt((double)size);
	current = 0;
	previous = index = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", index, array[index]);

		/* Check if the value is found at the current index */
		if (array[index] == value)
			return (index);

		/* Increment the current index and the step size */
		current++;
		index = current * step;

	} while (index < (int)size && array[index] < value);

	printf("Value found between indexes [%d] and [%d]\n", previous, index);

	for (previous = index; previous <= index && previous < (int)size; previous++)
	{
		printf("Value checked array[%d] = [%d]\n", previous, array[previous]);

		if (array[previous] == value)
			return (previous);
	}

	return (-1);
}
