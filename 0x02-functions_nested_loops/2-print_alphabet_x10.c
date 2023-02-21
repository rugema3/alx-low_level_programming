
/**
 * print_alphabet_x10 - prints 10 times the alphabet lowercase
 * return ;0 ( success)
 *
 */
#include"main.h"

void print_alphabet_x10(void)
{
	char k;
	int l;

	for (k = 0; k < 10; k++)
	{
		for (l = 'a'; l <= 'z'; l++)
			_putchar(l);
		_putchar('\n');
	}
}
