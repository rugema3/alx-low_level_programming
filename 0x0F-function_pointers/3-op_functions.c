#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * op_add - returns the sum of a and b
 * @a: first integer
 * @b: second integer
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
    return (a + b);
}

/**
 * op_sub - returns the difference of a and b
 * @a: first integer
 * @b: second integer
 * Return: difference of a and b
 */
int op_sub(int a, int b)
{
    return (a - b);
}

/**
 * op_mul - returns the product of a and b
 * @a: first integer
 * @b: second integer
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
    return (a * b);
}

/**
 * op_div - returns the result of the division of a by b
 * @a: first integer
 * @b: second integer
 * Return: result of the division of a by b
 */
int op_div(int a, int b)
{
    if (b == 0)
    {
        printf("Error\n");
        exit(100);
    }
    return (a / b);
}

/**
 * op_mod - returns the remainder of the division of a by b
 * @a: first integer
 * @b: second integer
 * Return: remainder of the division of a by b
 */
int op_mod(int a, int b)
{
    if (b == 0)
    {
        printf("Error\n");
        exit(100);
    }
    return (a % b);
}

/**
 * get_op_func - selects the correct function to perform the operation
 * @s: operator passed as argument to the program
 * Return: pointer to the function that corresponds to the operator given
 */
int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i;

    i = 0;
    while (ops[i].op != NULL)
    {
        if (strcmp(ops[i].op, s) == 0)
        {
            return (ops[i].f);
        }
        i++;
    }
    return (NULL);
}
