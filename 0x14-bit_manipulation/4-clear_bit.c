#include"main.h"
/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: Pointer to the number to clear the bit from
 * @index: Index of the bit to clear, starting from 0
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_mask = 1;

	/* Check if index is greater than the number of bits in unsigned long int */
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* Shift 1 to the left by index bits */
	bit_mask <<= index;

	/* Invert the mask to get all 1s except at the bit we want to clear */
	bit_mask = ~bit_mask;

	/* AND n with the inverted mask to clear the bit at index */
	*n &= bit_mask;

	return (1);
}

