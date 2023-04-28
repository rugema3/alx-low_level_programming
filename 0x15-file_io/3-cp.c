#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * exit_with_error - prints an error message to the standard error and exits
 * the program with the specified code
 * @code: the exit code
 * @message: the error message format string
 * @arg: the argument for the error message format string
 */
void exit_with_error(int code, char *message, char *arg);

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments
 * @argv: the arguments
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, read_count, write_count;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		exit_with_error(98, "Error: Can't read from file %s\n", argv[1]);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
		exit_with_error(99, "Error: Can't write to %s\n", argv[2]);

	do {
		read_count = read(file_from, buffer, BUFFER_SIZE);
		if (read_count == -1)
			exit_with_error(98, "Error: Can't read from file %s\n", argv[1]);

		write_count = write(file_to, buffer, read_count);
		if (write_count == -1)
			exit_with_error(99, "Error: Can't write to %s\n", argv[2]);

	} while (read_count == BUFFER_SIZE);

	if (close(file_from) == -1)
		exit_with_error(100, "Error: Can't close fd %d\n", file_from);

	if (close(file_to) == -1)
		exit_with_error(100, "Error: Can't close fd %d\n", file_to);

	return (0);
}

/**
 * exit_with_error - prints an error message and exits the program
 * @code: the exit code to use
 * @message: the error message to print
 * @arg: the argument to the error message
 *
 * Return: void
 */
void exit_with_error(int code, char *message, char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

