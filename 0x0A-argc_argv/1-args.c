/**
 * main - main program
 * Return: 0 (success)
 * @argc: count arguments
 * @argv:arguments
 */
#include<stdio.h>
#include"main.h"

int main(int argc, char *argv[])
{
	(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
