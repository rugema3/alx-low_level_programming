#include<stdio.h>

/**
 * main - entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	int num = 48; /* representing zero in decimal*/

	while (num <= 102) /* 102 is the representation of f*/
	{
		putchar(num);
		if (num == 57)
		{
			num += 39;
		}
		num++;
	}
		putchar('\n');
		return (0);
}
