#include "search_algos.h"

/**
 * interpolation_search - Search for a value in a sorted array
 * using Interpolation Search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: Index where 'value' is located, or -1 if not found.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;

	if (array == NULL)
		return (-1);

	for (;;)
	{
		size_t pos;
		double slope = (double)(high - low) / (array[high] - array[low]);

		if (low > high || value < array[low] || value > array[high])
		{
			printf("Value checked array[%lu] is out of range\n", low);
			return (-1);
		}

		pos = low + (slope * (value - array[low]));
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return ((int)pos);
		else if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	return (-1);
}
