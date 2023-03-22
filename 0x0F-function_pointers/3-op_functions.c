#include "3-calc.h"

/**
 * op_add - Returns the sum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Sum of a and b
 */
int op_add(int a, int b)
{
    return (a + b);
}

/**
 * op_sub - Returns the difference of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Difference of a and b
 */
int op_sub(int a, int b)
{
    return (a - b);
}

/**
 * op_mul - Returns the product of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Product of a and b
 */
int op_mul(int a, int b)
{
    return (a * b);
}

/**
 * op_div - Returns the division of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Division of a and b
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
 * op_mod - Returns the modulo of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Modulo of a and b
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

