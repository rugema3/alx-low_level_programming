#include <stdlib.h>
#include <stdio.h>

/**
 * main - Prints the opcodes of its own main function
 *
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 if successful, 1 if the number of arguments is incorrect,
 *         and 2 if the number of bytes is negative.
 */
int main(int argc, char *argv[])
{
    int num_bytes, i;
    char *func_ptr;
    void (*main_ptr)(void);

    if (argc != 2)
    {
        printf("Error\n");
        return (1);
    }
    num_bytes = atoi(argv[1]);
    if (num_bytes < 0)
    {
        printf("Error\n");
        return (2);
    }
    main_ptr = &main;
    func_ptr = (char *)main_ptr;
    for (i = 0; i < num_bytes; i++)
    {
        printf("%.2hhx ", func_ptr[i]);
    }
    printf("\n");
    return (0);
}

