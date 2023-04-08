/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the unsigned long integer where the bit needs to be set.
 * @index: The index (starting from 0) of the bit to be set.
 *
 * Return: 1 on success, -1 on error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	/* Check if index is out of range for unsigned long int */
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	/* Shift 1 to the left by index positions to create a mask */
	mask = 1UL << index;

	/* Use bitwise OR operation to set the bit at the index */
	*n = *n | mask;
	return (1);
}

