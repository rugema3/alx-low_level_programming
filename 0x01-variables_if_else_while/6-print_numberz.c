#include<stdio.h>

/**
 * main - this program prints alphabets in lowercase.
 *
 * Return: 0 (Success)
 */

int main(void)
{

	int  ch = 0;

	while (ch < 10)
	{
		putchar(ch + '0');
		/*converting ch to ASCII*/
		ch++;
	}
	putchar('\n');
	return (0);

}
