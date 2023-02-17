#include<stdio.h>

/**
 * main - this program prints alphabets in lowercase.
 *
 * Return: 0 (Success)
 */

int main(void)
{

	char ch = 'a';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	char h = 'A';

	while (h <= 'Z')
	{
		putchar(ch);
		h++;
	}
	putchar('\n');
	return (0);

}
