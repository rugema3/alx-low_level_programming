#include "main.h"

/**
 * binary_to_uint - converts a binary string to an unsigned int.
 * @binary_string: pointer to a string of 0 and 1 chars.
 *
 * Return: the converted number, or 0 if there is one
 * or more chars in the string
 * that is not 0 or 1 or if b is NULL.
 */
unsigned int binary_to_uint(const char *binary_string)
{
	unsigned int result = 0;

	/* Check if input string is NULL */
	if (!binary_string)
		return (0);

	/* Iterate over input string */
	for (; *binary_string != '\0'; binary_string++)
	{
		/* Check if current char is a valid binary digit */
		if (*binary_string == '0' || *binary_string == '1')
		{
			/* Shift left and add current binary digit to the result */
			result <<= 1;
			result += (*binary_string - '0');
		}
		else
		{
			/* Invalid binary digit found, return 0 */
			return (0);
		}
	}

	/* Return the converted unsigned int */
	return (result);
}

