
#include<stdio.h>

/**
 * print_to_98 - print n to 98 counts
 * @n: input
 */


void print_to_98(int n)
{
	int n;


	while (n < 98)
	{
		printf("%d", n);
		printf(",");
		printf(" ");
		n++;
	}
	while (n >= 98)
	{
		printf("%d", n);
		printf(" ");
		printf(",");
		n--;
	}
	printf("\n);
	
}
