#include<stdio.h>

/**
 * main - this program prints alphabets in lowercase.
 *
 * Return: 0 (Success)
 */

int main(void)
{

	int  ch = 'z';

	while (ch >= 'a')
	{
		putchar(ch);
		ch--;
	}
	putchar('\n');
	return (0);

}
