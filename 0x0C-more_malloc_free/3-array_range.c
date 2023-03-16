/**
 * array_range - Create an array of integers
 * @min: Minimum value for the array
 * @max: Maximum value for the array
 *
 * Return: Pointer to the newly created array, or NULL if an error occurred
 */
#include<stdlib.h>
int *array_range(int min, int max)
{
	int *arr, i, size;

	/* Check for invalid arguments */
	if (min > max)
		return (NULL);
	/* Calculate the size of the array */
	size = max - min + 1;
	/* Allocate memory for the array */
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	/* Fill the array with values from min to max */
	for (i = 0; i < size; i++)
	{
		arr[i] = min + i;
	}
	return (arr);
}
