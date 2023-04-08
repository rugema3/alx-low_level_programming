/**
 * clear_bit - Clear the value of a bit at a given index
 * @n: Pointer to the unsigned long integer to modify
 * @index: The index of the bit to clear, starting from 0 (LSB)
 *
 * Return: 1 if the bit was cleared successfully, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	/* Check if the index is within the valid range */
	do {
		if (index >= sizeof(unsigned long int) * 8)
		{
			/* Invalid index, return -1 to indicate an error */
			return (-1);
		}
	} while (0);

	/* Create a mask with only the bit at the given index set to 0 */
	mask = ~(1UL << index);

	/* Use bitwise AND operation to clear the bit at the index */
	*n &= mask;

	/* Return 1 to indicate success */
	return (1);
}

