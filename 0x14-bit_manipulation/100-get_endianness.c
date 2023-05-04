#include"main.h"
/**
 * flip_bits - Returns the number of bits that differ between two numbers
 * @num1: First number to compare
 * @num2: Second number to compare
 *
 * Return: Number of bits that need to be flipped
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	/* Calculate the XOR of the two numbers */
	unsigned long int xor_result = num1 ^ num2;

	/* Initialize a bit count variable to 0 */
	unsigned int bit_count = 0;

	/* Count the number of set bits in the XOR result */
	for (; xor_result > 0; xor_result >>= 1)
	{
		/* If the least significant bit is set, increment the bit count */
		if (xor_result & 1)
			bit_count++;
	}

	/* Return the number of bits that need to be flipped */
	return (bit_count);
}

