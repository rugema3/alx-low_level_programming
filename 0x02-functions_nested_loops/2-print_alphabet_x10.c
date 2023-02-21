
/**
 * print_alphabet_x10 - prints 10 times the alphabet lowercase
 * return ;0 ( success)
 */
#include<main.h>

void print_alphabet_x10(void)
{
	int a = 0;

	while (a < 10)
	{
		a++;
		int ch = 'a'

		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
	}
}
