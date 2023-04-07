#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Convert a binary string to an unsigned integer
 * @b: Pointer to the binary string
 *
 * Return: The unsigned integer representation of the binary string.
 * or 0 if the input string contains invalid characters or is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int sum = 0;
	/*Variable to store the resulting sum of the decimal value*/
	int i = 0;
	/**
	 * Variable to keep track of the current
	 *  character in the binary string
	 */

	if (b == NULL)  /* If the input string is NULL, return 0 */
		return (0);

	/* Loop through each character in the binary string */
	while (b[i] != '\0')
	{
		/* Shift the result to the left by 1 bit to make room for the next bit */
		sum = sum << 1;

		/**
		 * If the current bit is '1', set the least
		 * significant bit of the result to 1
		 */
		if (b[i] == '1')
		{
			sum = sum | 1;
		}

		i++;  /* Move to the next character in the binary string */
	}

	return (sum);  /* Return the final unsigned integer result */
}

