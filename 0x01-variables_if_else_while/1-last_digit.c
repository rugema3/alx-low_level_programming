#include <stdlib.h>
#include <time.h>
#include<stdio.h>

/**
 * main - the program will assign a random number
 * to the number n
 *
 * Return: 0 ( Success)
 *
 */
int main(void)
{
	int n;
	int last_num;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last_num = n % 10;
	if (last_num > 5)
	{
		print("last digit of %d is %d and is greater than 5\n", n, last_num);
	}
	else if (last_num == 0)
	{
		printf("last digit of %d is %d and is 0\n", n, last_num);
	}
	else
	{
		printf("last digit of %d is %d and is less than 6 and not 0\n", n, last_num);
	}
	return (0);
}
