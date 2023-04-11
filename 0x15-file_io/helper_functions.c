#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * open_file - Open a file with given flags and mode
 * @filename: Name of the file to open
 * @flags: Flags for opening the file (e.g., O_RDONLY, O_WRONLY, etc.)
 * @mode: Mode for creating the file (used with O_CREAT flag)
 *
 * Return: File descriptor of the opened file
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return fd;
}

/**
 * close_file - Close a file
 * @fd: File descriptor of the file to close
 *
 * Return: None
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		perror("Error closing file");
		exit(EXIT_FAILURE);
	}
}

/**
 * copy_file - Copy data from source file to destination file
 * @file_from: Name of the source file
 * @file_to: Name of the destination file
 *
 * Return: None
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_src, fd_dest;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	/* Open source file for reading */
	fd_src = open_file(file_from, O_RDONLY, 0);

	/* Open destination file for writing, create if not exist, truncate if exist */
	fd_dest = open_file(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	/* Copy data from source file to destination file */
	while ((bytes_read = read(fd_src, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_dest, buffer, bytes_read);
		if (bytes_written == -1)
		{
			perror("Error writing to file");
			exit(EXIT_FAILURE);
		}
	}

	if (bytes_read == -1)
	{
		perror("Error reading from file");
		exit(EXIT_FAILURE);
	}

	/* Close source and destination files */
	close_file(fd_src);
	close_file(fd_dest);

	printf("File '%s' copied to '%s' successfully.\n", file_from, file_to);
}

