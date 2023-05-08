#include"main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file.
 * @text_content: Text to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 *         If filename is NULL return -1.
 *         If text_content is NULL, do not add anything to the file.
 *         Return 1 if the file exists and -1 if the file does not exist or
 *         if you do not have the required permissions to write the file.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, num_written, len = 0;

	if (filename == NULL)
		return (-1);

	/* Open the file in append mode */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* If text_content is not NULL, get its length and append it to the file */
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
		num_written = write(fd, text_content, len);
		if (num_written == -1 || num_written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

