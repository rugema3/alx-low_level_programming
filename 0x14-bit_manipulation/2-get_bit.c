#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @num: the number to get the bit from
 * @index: the index of the bit to get, starting from 0
 *
 * Return: the value of the bit at index index, or -1 if an error occured
 */
int get_bit(unsigned long int num, unsigned int index)
{
	unsigned long int bit_mask;

	/* Check if index is greater than the number of bits in unsigned long int */
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* Shift 1 to the left by index bits */
	bit_mask = 1UL << index;

	/**
	 * If the AND of num and the mask is non-zero,
	 * the bit at index is 1, otherwise 0
	 */
	return ((num & bit_mask) != 0);
}

