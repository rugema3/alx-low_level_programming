/**
 * _realloc - Reallocate a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated with malloc
 * @old_size: Size of the allocated space for ptr
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block,or
 * NULL if an error occurred
 */
#include<stdlib.h>
#include <string.h>
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	/* Handle special cases */

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	/* Allocate memory for the new block */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	/* Copy the contents of the old block to the new block */
	if (new_size > old_size)
	{
		memcpy(new_ptr, ptr, old_size);
	}
	else
	{
		memcpy(new_ptr, ptr, new_size);
	}
	/* Free the old block */
	free(ptr);
	return (new_ptr);
}
