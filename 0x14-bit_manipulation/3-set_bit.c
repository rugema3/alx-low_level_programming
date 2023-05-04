#include"main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the number to set the bit in
 * @index: the index of the bit to set, starting from 0
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	/* Check if index is greater than the number of bits in unsigned long int */
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* Shift 1 to the left by index bits */
	mask = 1UL << index;

	/* Use the ternary operator to set the bit at index */
	*n = (*n & ~mask) | ((1UL << index) ? 1UL << index : 0);

	return (1);
}

