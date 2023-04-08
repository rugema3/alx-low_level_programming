#include "main.h"
#include <stddef.h>
#include<ctype.h>
#include <limits.h>
/**
 * binary_to_uint - Convert a binary string to an unsigned integer
 * @b: Pointer to the binary string
 *
 * Return: The unsigned integer representation of the binary string,
 *         or 0 if the input string contains invalid characters or is NULL,
 *         or if the resulting value exceeds the maximum representable value
 *         of an unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int sum = 0;
	int i = 0;
	unsigned int max_uint = UINT_MAX;

	if (b == NULL)  /* If the input string is NULL, return 0 */
		return (0);

	/* Loop through each character in the binary string */
	while (b[i] != '\0')
	{
		/* Validate that the character is a valid digit (either '0' or '1') */
		if (!isdigit(b[i]))
			return (0);  /* If invalid character found, return 0 */

		/* Shift the result to the left by 1 bit to make room for the next bit */
		sum <<= 1;

		/**
		 *  If the current bit is '1',
		 *   set the least significant bit of the result to 1
		 */
		if (b[i] == '1')
			sum |= 1;

		i++;  /* Move to the next character in the binary string */
	}

	/**
	 *  Check for overflow by comparing with maximum
	 *   representable value of unsigned int
	 */
	if (sum > max_uint)
		return (0);  /* If overflow, return 0 */

	return (sum);  /* Return the final unsigned integer result */
}

