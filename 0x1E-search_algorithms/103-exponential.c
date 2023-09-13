#include <stdio.h>

/**
 * binary_search - a function that searches for a value in
 * a sorted array of integers  using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @sideA: The starting index of the array to search in
 * @sideB: The ending index of the array to search in
 *
 * Return: If value is not present in array or
 * if array is NULL, function must return -1
 * function must return the index where value is located
 */
int binary_search(int *array, size_t sideA, size_t sideB, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (sideB >= sideA)
	{
		printf("Searching in array: ");

		for (i = sideA; i < sideB; i++)
		{
			printf("%d, ", array[i]);
		}
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

/**
 * exponential_search - searches for a value in a sorted array of
 * integers using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: If value is not present in array or
 * if array is NULL, function must return -1
 * function must return the index where value is located
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t sideB, i = 0;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
		{
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		}
	}

	sideB = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, sideB);
	return (binary_search(array, i / 2, sideB, value));
}
