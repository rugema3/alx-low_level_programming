/**
 * main - a program that prints all arguments it receives
 * @argc: count
 * @argv: argument
 * Return: 0 (success)
 */
#include<stdio.h>
#include"main.h"

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
