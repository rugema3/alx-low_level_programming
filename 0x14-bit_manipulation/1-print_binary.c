#include <stdio.h>
#include "main.h"

/**
 * print_binary - Print the binary representation of a number
 * @n: The unsigned long integer to print in binary
 */
void print_binary(unsigned long int n)
{
	int size = sizeof(n) * 8;
	/* Number of bits in an unsigned long integer */

	int i;

	unsigned long int mask = 1UL << (size - 1);
	/* Mask to extract each bit from left to right */

	int leading_zeroes = 1;  /* Flag to track leading zeroes */

	/* Loop through each bit in the number and print its binary representation */
	for (i = 0; i < size; i++)
	{
		/* Use bitwise AND operation to extract the current bit */
		unsigned long int bit = (n & mask) ? 1 : 0;

		/* If a non-zero bit is found, set the flag to false */
		if (bit)
			leading_zeroes = 0;
		/* Print the binary representation of the current bit if not leading zero */
		if (!leading_zeroes)
			_putchar('0' + bit);
		/* Shift the mask to the right by 1 bit for the next iteration */
		mask >>= 1;
	}
	/* If the number is zero, print a single '0' */
	if (leading_zeroes)
		_putchar('0');
	_putchar('\n');  /* Print a newline character at the end */
}

