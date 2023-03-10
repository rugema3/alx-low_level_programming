#include<stdio.h>
#include<stdlib.h>
#include"main.h"

/**
 * main - a program that prints the minimum number of coins to make change
 * @argc: count arguments
 * @argv: arguments
 * Return: 0 ( sucess) 1 (error)
 */

int main(int argc, char *argv[])
{
	int i, j, k;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	i = atoi(argv[1]);
	k = 0;
	if (i < 0)
	{
		printf("0\n");
		return (0);
	}
	for (j = 0; j < 5 && i >= 0; j++)
	{
		while (i >= coins[j])
		{
			k++;
			i = i - coins[j];
		}
	}
	printf("%d\n", k);
	return (0);
}
