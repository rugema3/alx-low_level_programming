#include"main.h"

/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	/* Create a test value with a known byte order */
	unsigned int test = 0x76543210;
	/* Cast a pointer to the test value as a character pointer */
	char *byte = (char *)&test;

	/**
	 * If the first byte of the test value is 0x10,
	 * then the system is little endian
	 */
	if (*byte == 0x10)
	{
		/* Least significant byte stored first (little endian) */
		return (1);
	}
	else
	{
		/* If the first byte of the test value is not 0x10, */
		/*then the system is big endian */
		/* Most significant byte stored first (big endian) */
		return (0);
	}
}

