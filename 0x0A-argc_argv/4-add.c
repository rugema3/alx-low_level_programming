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

int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc >= 1)
	{
		for (i = 1; i < argc; i++)
		{
			sum = sum + atoi(argv[i]);
		}
		printf("%d\n", sum);
	}
	else
	{
		printf("0\n");
	}
	return (0);
}
