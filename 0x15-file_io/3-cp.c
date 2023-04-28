#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * open_file - Opens a file with given flags and mode.
 *
 * @filename: The name of the file to open.
 * @flags: The flags to specify the mode of file opening.
 * @mode: The file permission mode for creating a new file.
 *
 * Return: The file descriptor (fd) of the opened file.
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * close_file - Closes a file.
 *
 * @fd: The file descriptor (fd) of the file to close.
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
 * copy_file - Copies data from source file to destination file.
 *
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 * @force: A flag indicating whether to overwrite the destination file if it already exists.
 */
void copy_file(const char *file_from, const char *file_to, int force)
{
	int fd_src, fd_dest;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];
	/* Open source file for reading */
	fd_src = open_file(file_from, O_RDONLY, 0);

	/* Check if the destination file already exists */
	if (access(file_to, F_OK) == 0)
	{
		if (!force)
		{
			printf("File %s already exists. Do you want to overwrite it? (y/n) ", file_to);
			char answer;
			scanf("%c", &answer);

			if (answer != 'y' && answer != 'Y')
			{
				printf("File not copied.\n");
				exit(EXIT_SUCCESS);
			}
		}
				if (access(file_to, W_OK) != 0)
		{
			perror("Error: Destination file cannot be overwritten");
			exit(EXIT_FAILURE);
		}
	}
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
	close_file(fd_src);
	close_file(fd_dest);
	printf("File '%s' copied to '%s' successfully.\n", file_from, file_to);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: 0 on success, non-zero value on failure.
 */
int main(int argc, char *argv[])
{
	const char *file_from; /* Source file name */
	const char *file_to;   /* Destination file name */
	int force_flag = 0;    /* Flag to check if force option is present */

	if (argc < 3 || argc > 4)
	{
		fprintf(stderr, "Usage: %s <file_from> <file_to> [force]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file_from = argv[1];
	file_to = argv[2];
	if (access(file_from, F_OK) == -1)
	{
		perror(file_from);
		exit(EXIT_FAILURE);
	}
	if (access(file_to, F_OK) != -1 && argc != 4)
	{
		fprintf(stderr, "File %s already exists. Use -f to overwrite.\n", file_to);
		exit(EXIT_FAILURE);
	}
	if (argc == 4 && strcmp(argv[3], "force") == 0)
	{
		force_flag = 1;
	}
	if (force_flag)
	{
		copy_file(file_from, file_to);
	}
	else
	{
		char confirm;

		printf("File %s already exists. Do you want to overwrite? (y/n): ", file_to);
		scanf(" %c", &confirm);
		if (confirm == 'y' || confirm == 'Y')
		{
			copy_file(file_from, file_to);
		}
		else
		{
			printf("File not copied.\n");
			exit(EXIT_SUCCESS);
		}
	}

	return (0);
}

