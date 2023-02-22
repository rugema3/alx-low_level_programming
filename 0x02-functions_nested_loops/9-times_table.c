#include"main.h"
/**
 * times_table _ prints 9 multiplication table
 * Description: This program prints the multiplication table of 9
 * Return: void
 */
void times_table(void)
{
	int row, column, product, tens, ones;

	for (row = 0; row <= 9; row++)
	{
		for (column = 0; column <= 0; column++)
		{
			product = row * column;

			tens = product / 10;
			ones = product % 10;
			if (column == 0)
			{
				_putchat('0');
			}
			else if (product < 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(ones + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				_putchar(tens + '0');
				_putchar(ones + '0');
			}
		}
		_putchar('\n');
	}
}


