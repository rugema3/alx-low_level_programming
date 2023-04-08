/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	/* Create a multi-byte value with a known pattern */
	unsigned int value = 0x01;

	/* Shift the value to the right to isolate the first byte */
	unsigned char byte = (unsigned char)(value >> (sizeof(unsigned int) - 1) * 8);
	/* Check the value of the first byte to determine the endianness */

	if (byte == 0x01)
	{
		/* If the first byte is 0x01, it means the system is little endian */
		return (1); /* little endian */
	}
	else
	{
		/* Otherwise, the system is big endian */
		return (0); /* big endian */
	}
}

