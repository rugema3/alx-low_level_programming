/**
 * main - entry of a program
 * @argc: count arguments
 * @argv: arguments
 * Return: 0 ( success)
 */

#include<stdio.h>
#include"main.h"

int main(int argc, char *argv[])
{
	(void) argc;
	printf("%s\n", argv[0]);
	return (0);
}
