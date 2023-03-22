#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point
 *
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
    int a, b;
    int (*op_func)(int, int);
    int result;

    if (argc != 4)
    {
        printf("Error\n");
        exit(98);
    }

    a = atoi(argv[1]);
    b = atoi(argv[3]);

    op_func = get_op_func(argv[2]);

    if (op_func == NULL)
    {
        printf("Error\n");
        exit(99);
    }

    if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
    {
        printf("Error\n");
        exit(100);
    }

    result = op_func(a, b);

    printf("%d\n", result);

    return (0);
}

