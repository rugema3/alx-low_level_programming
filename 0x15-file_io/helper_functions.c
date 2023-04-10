#include <stdlib.h>
#include<stdio.h>
#include <stdarg.h>
/**
 * print_error - Prints an error message to stderr
 * @msg: The error message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
}

/**
 * exit_with_error - Print an error message to
 *stderr and exit with an error code.
 *
 * This function takes an error code, an error message format string, and a
 * variable number of arguments to be used with the format string. The error
 * message is formatted using vfprintf() and printed to stderr. The function
 * then exits with the given error code.
 * err_code: The error code to exit with.
 * msg: The error message format string.
 * Additional arguments to be used with the format string.
 *
 * Return: Nothing.
 */
void exit_with_error(int err_code, const char *msg, ...)
{
	va_list args;
	/* Create a va_list to store the variable arguments */
	va_start(args, msg);
	/* Initialize the va_list with the last named argument (msg) */

	/* Format and print the error message to stderr using vfprintf() */
	vfprintf(stderr, msg, args);

	va_end(args); /* Clean up the va_list */

	fprintf(stderr, "\n");
	/* Print a newline character after the error message */

	exit(err_code); /* Exit the program with the given error code */
}

