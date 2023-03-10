/**
 * main - a program that multiplies two numbers
 * @argc: argument count
 * @argv: argument
 * Return: 0 (success) or 1 for error
 *
 */

#include<stdio.h>
#include"main.h"
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int i, mul = 1;

	if (argc > 1 && argc >= 3)
	{
		for (i = 1; i < argc; i++)
		{
			mul = mul * atoi(argv[i]);
		}
		printf("%d\n", mul);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
