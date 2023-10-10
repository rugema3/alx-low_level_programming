#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursive function to perform
 * advanced binary search.
 * @array: Pointer to the first element of the array to search in.
 * @left: Index of the left boundary.
 * @right: Index of the right boundary.
 * @value: The value to search for.
 *
 * Return: Index where 'value' is located, or -1 if not found.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i, mid;

	if (left > right)
		return (-1);

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
	{
		if (mid > 0 && array[mid - 1] == value)
			return (advanced_binary_recursive(array, left, mid, value));
		return ((int)mid);
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, right, value));
	else
		return (advanced_binary_recursive(array, left, mid - 1, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using
 * Advanced Binary Search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: Index where 'value' is located, or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
