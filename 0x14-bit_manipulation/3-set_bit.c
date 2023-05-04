#include"main.h"
/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @num: pointer to the number to set the bit in
 * @i: the index of the bit to set, starting from 0
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *num, unsigned int i)
{
	/* Check if index is greater than the number of bits in unsigned long int */
	if (i >= sizeof(unsigned long int) * 8)
		return (-1);

	/* Shift 1 to the left by index bits */
	unsigned long int bit_mask = 1UL << i;

	/* Use the ternary operator to set the bit at index */
	*num = (*num & ~bit_mask) | ((1UL << i) ? 1UL << i : 0);

	return (1);
}

