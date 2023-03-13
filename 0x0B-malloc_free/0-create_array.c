#include <stdlib.h>

/**
 * create_array - creates an array of chars
 * and initializes it with a specific char
 * @size: the size of the array to create
 * @c: the char to initialize the array with
 *
 * Return: On success, returns a pointer to the created array. On failure,
 * returns NULL.
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0) /* If size is zero, return NULL */
		return (NULL);
	array = (char *) malloc(size * sizeof(char));
	/* Allocate memoryfor the array */

	if (array == NULL) /* If memory allocation fails, return NULL */
		return (NULL);
	for (i = 0; i < size; i++)
		array[i] = c; /* Set each element of the array to the specified char */
	return (array); /* Return a pointer to the array */
}
