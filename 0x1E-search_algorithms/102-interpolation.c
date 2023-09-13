#include <stdio.h>

/**
 * interpolation_search -  searches for a value in a sorted array of
 * integers using the Interpolation search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: return the first index where value is located
 * If value is not present in array or if array is NULL,
 * function must return -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, low, high;
	double factor;

	if (array == NULL)
		return (-1);

	low = 0;
	high = size - 1;

	while (size) {
		factor = (double)(high - low) / (array[high] - array[low]) * (value - array[low]);
		pos = (size_t)(low + factor);
		printf("Value checked array[%d]", (int)pos);

		if (pos >= size) {
			printf(" is out of range\n");
			break;
		} else {
			printf(" = [%d]\n", array[pos]);
		}

		if (array[pos] < value) {
			low = pos + 1;
		} else {
			high = pos - 1;
		}

		if (array[pos] == value)
			return ((int)pos);

		if (low == high)
			break;
	}

	return (-1);
}
