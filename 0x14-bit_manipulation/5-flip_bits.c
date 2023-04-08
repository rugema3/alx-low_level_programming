#include"main.h"
/**
 * flip_bits - Calculate the number of bits needed to flip to
 *             get from one number to another
 * @n: The first unsigned long integer
 * @m: The second unsigned long integer
 *
 * Return: The number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;  /* Counter for flipped bits */

	/* Calculate the XOR of n and m to get the differing bits */
	unsigned long int diff = n ^ m;

	/**
	 *  Count the number of set bits (1s) in
	 *  the XOR result using a do-while loop
	 */
	do {
		/* Use bitwise AND operation to check if the least significant bit is set */
		if (diff & 1)
			count++;  /* Increment the count if the bit is set */
		/* Shift the XOR result to the right by 1 bit for the next iteration */
		diff >>= 1;
	} while (diff);

	/* Return the count of flipped bits */
	return (count);
}

