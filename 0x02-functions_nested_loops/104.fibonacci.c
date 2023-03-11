/**
 * fibonacci - this function prints the first fibonaci 
 * numbers starting with 1 and 2
 * @n: number of fibonaccis to be printed
 * Return: Recursive
 */

#include <stdio.h>
#include<float.h>

double fibonacci(double n)
{
    /* base cases that will terminate the program.*/
    if (n == 1)
    {
        return (1);
    }
    else if (n == 2)
    {
        return (2);
    }
    else
    {
        /* recursive case */
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

/**
 * main - the entry point
 * Return: 0 ( success)
 */

int main() 
{
    /* loop to print the first 98 Fibonacci numbers */
    for (double i = 1; i <= 98; i++)
    {
        printf("%.0f\n", fibonacci(i));
    }

    return (0);
}
