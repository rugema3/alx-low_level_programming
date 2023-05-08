#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int open_file(const char *filename, int flags, mode_t mode);
ssize_t read_write_file(int fd_from, int fd_to, char *buf, size_t size);
int close_file(int fd);

/**
 * main - program entry point
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, or an exit code on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, status;
	char buf[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (EXIT_FAILURE);
	}
	fd_from = open_file(argv[1], O_RDONLY, 0);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	fd_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(fd_from);
		return (EXIT_FAILURE);
	}
	status = read_write_file(fd_from, fd_to, buf, BUF_SIZE);
	if (status != 0)
	{
		close_file(fd_from);
		close_file(fd_to);
		return (EXIT_FAILURE);
	}
	status = close_file(fd_from);
	if (status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		return (EXIT_FAILURE);
	}
	status = close_file(fd_to);
	if (status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * open_file - opens a file with specified flags and mode
 * @filename: the name of the file to open
 * @flags: the flags to use when opening the file
 * @mode: the mode to use when creating the file
 *
 * Return: the file descriptor of the opened file, or -1 on failure
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		perror("open");
	}
	return (fd);
}
/**
 * read_write_file - reads from one file and writes to another
 * @fd_from: the file descriptor of the file to read from
 * @fd_to: the file descriptor of the file to write to
 * @buf: the buffer to use for reading and writing
 * @size: the size of the buffer
 *
 * Return: 0 on success, or -1 on failure
 */
ssize_t read_write_file(int fd_from, int fd_to, char *buf, size_t size)
{
	ssize_t rcount, wcount;

	do {
		rcount = read(fd_from, buf, size);
		if (rcount == -1)
		{
			perror("read");
			return (-1);
		}

		wcount = write(fd_to, buf, rcount);
		if (wcount == -1 || wcount != rcount)
		{
			perror("write");
			return (-1);
		}
	} while (rcount > 0);

	return (0);
}
/**
 * close_file - closes a file with the specified file descriptor
 * @fd: the file descriptor of the file to close
 *
 * Return: 0 on success, or -1 on failure
 */
int close_file(int fd)
{
	int status = close(fd);

	if (status == -1)
	{
		perror("close");
	}
	return (status);
}

