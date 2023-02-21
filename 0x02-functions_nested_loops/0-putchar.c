#include "main.h"
/**
 * main - the entry point:This program prints _putchar, followed by a new line
 *
 *Return: 0 (Success)
 */
int main(void)
{
	char str[] = "_putchar";
	int ch;

	for (ch = 0; ch < 8; ch++)
		_putchar(str[ch]);
	_putchar('\n');

	return (0);

}


