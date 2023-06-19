#include"main.h"

/**
 * _puts - prints a string.
 *
 * @str: string parameter to print
 *
 * Return: Void
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str + 0);
		++str;
	}
	_putchar('\n');
}
