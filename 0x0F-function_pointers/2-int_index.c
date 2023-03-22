/**
 * int_index - searches for an integer in an array
 * @array: a pointer to the array to search
 * @size: the number of elements in the array
 * @cmp: a function pointer that takes an int as
 * an argument and returns an int
 *
 * This function searches for an integer in the
 * array using the provided function
 * pointer to compare values.
 * Return: It returns the index of the first element for which
 * the cmp function does not return 0. If no
 * element matches, it returns -1.
 */
#include <stddef.h>
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	/**
	 * we first check if array, cmp, and size are valid inputs
	 * before searching the array for
	 * the desired integer. If the function finds an element
	 * that matches, it returns its index.
	 * If no element matches, it returns -1.
	 */
	if (array != NULL && cmp != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
			{
				return (i);
			}
		}
	}
	return (-1);
}

