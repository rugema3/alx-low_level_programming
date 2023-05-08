#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

/**
 * error_exit - Print error message and exit with given error code.
 * @err_code: The error code to exit with.
 * @message: The error message to print.
 * @filename: The file name to include in the error message, or NULL.
 */
void error_exit(int err_code, const char *message, const char *filename);

/**
 * main - Entry point of the program.
 * @argc: The number of arguments passed.
 * @argv: The array of arguments.
 *
 * Return: 0 if successful, or an error code if any error occurs.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	char buffer[BUF_SIZE];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to", NULL);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
		error_exit(98, "Error: Can't read from file", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to < 0)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to", argv[2]);
	}

	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to", argv[2]);
		}
	}

	if (bytes_read < 0)
		error_exit(98, "Error: Can't read from file", argv[1]);

	if (close(fd_from) < 0)
		error_exit(100, "Error: Can't close fd", argv[1]);

	if (close(fd_to) < 0)
		error_exit(100, "Error: Can't close fd", argv[2]);

	return (0);
}

/**
 * error_exit - Print error message and exit with given error code.
 * @err_code: The error code to exit with.
 * @message: The error message to print.
 * @filename: The file name to include in the error message, or NULL.
 */
void error_exit(int err_code, const char *message, const char *filename)
{
	if (filename)
		dprintf(STDERR_FILENO, "%s %s\n", message, filename);
	else
		dprintf(STDERR_FILENO, "%s\n", message);
	exit(err_code);
}

