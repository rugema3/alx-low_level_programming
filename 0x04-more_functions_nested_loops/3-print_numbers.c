/**
 * prrint_numbers - The function prints numbers from 0-9'
 * return: 0 (success)
 *
 */
#include"main.h"
void print_numbers(void);
{
	int a = 0;

	do {
		_putchar(a);
		a++;
	} while (a >= 0 && a <= 9)
	_putchar('\n');
}
