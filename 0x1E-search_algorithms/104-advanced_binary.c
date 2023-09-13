#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If value is not present in array or
 * if array is NULL, function must return -1
 * function must return the index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
	{
		int index = half;

		while (index > 0 && array[index - 1] == value)
			index--;

		return (index);
	}

	if (value < array[half])
		return (advanced_binary(array, half + 1, value));

	half++;
	return (advanced_binary(array + half, size - half, value) + half);
}
