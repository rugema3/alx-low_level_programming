#include<stdio.h>

/**
 * main - this program prints alphabets in lowercase reverse.
 *
 * Return: 0 (Success)
 */

int main(void)
{

	char ch = 'z';

	while (ch >= 'a')
	{
		putchar(ch);
		ch--;
	}
	putchar('\n');
	return (0);

}
