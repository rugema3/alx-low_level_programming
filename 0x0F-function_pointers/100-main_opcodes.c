#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function
 *
 * @argc: The number of command-line arguments passed to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 if successful, 1 if the number of arguments is incorrect,
 *         and 2 if the number of bytes is negative.
 */
int main(int argc, char *argv[])
{
    int num_bytes, i;
    char *func_ptr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_bytes>\n", argv[0]);
        return 1;
    }

    num_bytes = atoi(argv[1]);

    if (num_bytes <= 0) {
        fprintf(stderr, "Error: num_bytes must be a positive integer\n");
        return 2;
    }

    func_ptr = (char *) main;

    printf("%p:\n", (void *) func_ptr);

    for (i = 0; i < num_bytes; i++) {
        printf("  %.2hhx ", func_ptr[i]);
    }

    printf("\n");

    return 0;
}

