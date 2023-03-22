/**
 * array_iterator - executes a function on each element of an array
 * @array: a pointer to the array to iterate over
 * @size: the number of elements in the array
 * @action: a function pointer that takes an int as
 * an argument and returns void
 *
 * This function iterates over each element in the array
 * and calls the provided function
 * with the current element as its argument.
 */
#include <stddef.h>
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;
	/**
	 * The implementation checks if array and action are not null
	 *  before iterating over the array and calling action with each element.
	 */
	if (array != NULL && action != NULL)
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
