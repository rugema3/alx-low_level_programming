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
	char ch = 'A';

	while (ch <= 'Z')
	{
		putchar(ch);
		ch++;
	}
	/*putchar('\n');*/
	return (0);

}
