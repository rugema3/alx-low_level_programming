#include<stdio.h>

/**
 * main - This program will print numbers less than 10.
 *
 * Return: 0 (success)
 */

int main(void)
{
	int num = 0;

	while (num < 10)
	{
		printf("%d", num);
		num++;
	}
	printf("\n");
	return (0);
}
