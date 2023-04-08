/**
 * get_bit - Get the value of a bit at a given index
 * @n: The unsigned long integer to extract the bit from
 * @index: The index of the bit to get, starting from 0 (LSB)
 *
 * Return: The value of the bit at the given index (0 or 1)
 *         or -1 if an error occurred (invalid index)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask, bit;

	/* Check if the index is within the valid range */
	if (index >= sizeof(unsigned long int) * 8)
	{
		/* Invalid index, return -1 to indicate an error */
		return (-1);
	}

	/* Create a mask with only the bit at the given index set to 1 */
	mask = 1UL << index;

	/* Use bitwise AND operation to extract the value of the bit at the index */
	bit = n & mask;

	/* Shift the extracted bit to the rightmost position and return its value */
	return (bit >> index);
}

