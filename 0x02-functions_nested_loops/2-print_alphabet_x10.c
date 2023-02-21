/**
 * print_alphabet_x10 - prints 10 times the alphabet lowercase
 * return ;0 ( success)
 */
#include"main.h"


void print_alphabet_x10(void)
{
	int line, ch;

	for (line = 0; line <= 9; ++line;
			{

			for (ch = 'a'; ch <= 'z'; ++ch)
			_putchar(ch);
			_putchar('\n');
			}
}
