#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * create_file - Create a file with specified permissions
 * and write text content to it
 * @filename: Name of the file to create
 * @text_content: NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure (file cannot be created,
 * file cannot be written, write "fails", etc...)
 * The created file must have permissions set to rw-------
 * If the file already exists, it will be truncated
 * If @filename is NULL, return -1
 * If @text_content is NULL, create an empty file
 */
int create_file(const char *filename, char *text_content)
{
	int fd; /* File descriptor */

	if (filename == NULL)
		return (-1); /* Return -1 if filename is NULL */

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	/*
	 * Open the file with write-only, create if not exist,
	 * truncate if exist,
	 * and set permissions to rw-------
	 * Note: S_IRUSR is equivalent to binary 0400,
	 * S_IWUSR is equivalent to binary 0200
	 */
	if (fd == -1)
		return (-1); /* Return -1 if file cannot be created or opened */

	if (text_content != NULL)
	{
		int length = strlen(text_content);
		int count = write(fd, text_content, length);
		/**
		 * count is an integer variable that holds the return value of
		 * the write system call, which represents the number of bytes
		 * actually written to the file.
		/*
		 * Write text_content to the file
		 * Note: write returns the number of bytes written,
		 * which should be equal to len
		 */
		if (count != length)
		{
			close(fd);
			return (-1); /* Return -1 if write fails */
		}
	}

	close(fd);
	return (1); /* Return 1 on success */
}

