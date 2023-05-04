#include"main.h"
/**
 * print_binary - prints the binary representation of a number
 * @num: the number to print in binary
 */
void print_binary(unsigned long int num)
{
	/* Create a bit mask with the most significant bit set */
	unsigned long int bit = 1UL << ((sizeof(unsigned long int) * 8) - 1);

	/* Flag to indicate if we have printed any 1s yet */
	int has_printed = 0;

	/* Iterate over each bit in the number */
	for (; bit > 0; bit >>= 1)
	{
		/* If the current bit is set, print 1 and set the has_printed flag */
		if (num & bit)
		{
			_putchar('1');
			has_printed = 1;
		}
		/**
		 * If the current bit is not set and we have already printed a 1,
		 * or if the current bit is the least significant bit, print 0
		 */
		else if (has_printed || bit == 1)
		{
			_putchar('0');
		}
	}
}

