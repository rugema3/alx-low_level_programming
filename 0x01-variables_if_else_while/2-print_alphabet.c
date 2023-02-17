#include<stdio.h>

/**
 * main - this program prints alphabets in lowercase.
 *
 * Return: 0 (Success)
 */

int main(void)
{

	char ch;
	ch = 'a';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	return (0);

}
