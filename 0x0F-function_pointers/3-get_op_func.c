#include <stdlib.h>
#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the
 *               operation asked by the user.
 * @s: The operator passed as argument.
 *
 * Return: A pointer to the function that corresponds to the
 *         operator given as a parameter.
 */
int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", add},
        {"-", sub},
        {"*", mul},
        {"/", div},
        {"%", mod},
        {NULL, NULL}
    };
    int i = 0;

    while (ops[i].op)
    {
        if (*(ops[i].op) == *s && !*(s + 1))
            return (ops[i].f);
        i++;
    }

    return (NULL);
}

