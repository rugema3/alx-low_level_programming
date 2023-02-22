#include"main.h"
/**
 * print_last_digit - This function prints the last didgit of a number
 *
 * @n: takes the number input
 *
 * Return: it returns the last digit
 *
 */
int print_last_digit(int n)
{
	int lastdigit;

	if (n < 0)
		lastdigit = -1 * (n % 10);
	else
		lastdigit = n % 10;
	_putchar(lastdigit + '0');
	return (lastdigit);
}
