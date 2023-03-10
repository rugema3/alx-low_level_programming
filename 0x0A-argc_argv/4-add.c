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
#include<ctype.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc >= 1)
	{
		for (i = 1; i < argc; i++)
		{
			if (is_number(argv[i]) == 0)
			sum = sum + atoi(argv[i]);
			else
			{
				printf("Error\n");
				return (1);
			}
		}
		printf("%d\n", sum);
	}
	else
	{
		printf("0\n");
	}
	return (0);
}

/**
 * is_number - a function checking for a digit
 * @n: string to be checked
 * Return: 0 if it is a number 1 if not.
 *
 */

int is_number(char n[])
{
	int i, leng = strlen(n);

	for (i = 0; i < leng; i++)
	{
		if (!isdigit(n[i]))
			return (1);
	}
	return (0);
}

