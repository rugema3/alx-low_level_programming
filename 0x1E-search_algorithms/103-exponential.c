#include "search_algos.h"
#include <stdio.h>



/**
 * my_binary_search - Search for a value in a sorted array using Binary Search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: Index where 'value' is located, or -1 if not found.
 */
int my_binary_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1, mid;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		size_t i;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			if (i == right)
				printf("%d", array[i]);
			else
				printf("%d, ", array[i]);
		}
		printf("\n");

		mid = (left + right) / 2;

		if (array[mid] == value)
			return ((int)mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
/**
 * exponential_search - Searches for a value in a sorted array using
 * Exponential Search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: Index where 'value' is located, or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	if (bound >= size)
	{
		printf("Value checked array[%lu] is out of range\n", bound / 2);
		return (-1);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, bound);


	return (my_binary_search(array + (bound / 2), size - (bound / 2), value));
}

