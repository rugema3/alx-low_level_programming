/**
 * _calloc - Allocate zero-initialized memory for an array
 * @nmemb: Number of elements in the array
 * @size: Size of each element in bytes
 *
 * Return: Pointer to the allocated memory, or NULL if an error occurred
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	/* Check for zero arguments */
	if (nmemb == 0 || size == 0)
		return (NULL);
	/* Allocate memory */
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	/* Zero-initialize the memory */
	memset(ptr, 0, nmemb * size);
	return (ptr);
}

