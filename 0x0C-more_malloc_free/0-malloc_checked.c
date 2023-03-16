/**
 * malloc_checked - Allocates memory using malloc
 *
 * @b: The number of bytes to allocate
 *
 * Return: If successful, a pointer to the allocated memory
 *         If malloc fails, the function terminates
 *         the program with a status value of 98
 */
#include<stdlib.h>
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
	{
		/* Malloc failed, terminate program with status 98 */
		exit(98);
	}
	return (ptr);
}
