#include"main.h"
/**
 * times_table - prints 9 multiplication table
 * Description:This program prints the multiplication table of 9 from 0
 * Return: void
 */
void times_table(void)
{
	int i, j, product;

	for (i = 0; 1 <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			product = i * j;
			_putchar(product);
			_putchar(',');
			_putchar(' ');
		}
		_putchar('\n');
	}
}


