/**
 * print_numbers - The function prints numbers from 0-9'
 * return: 0 (success)
 *
 */
#include"main.h"
void print_numbers(void)
{
	char a = 0;

	while (a <= 9)
	{
		_putchar(a + '0');
		a++;
	}
	_putchar('\n');
}
