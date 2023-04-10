#include <stdio.h>
#include <stdlib.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file
 * @text_content: The NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, const char *text_content)
{
	FILE *file_ptr;
	int result = -1; /* Default return value of -1 */

	if (filename == NULL)
		return (-1); /* If filename is NULL, return -1 */

	file_ptr = fopen(filename, "a"); /* Open file in append mode */
	if (file_ptr == NULL)
		return (-1); /* If file cannot be opened, return -1 */

	if (text_content != NULL)
	{
		if (fputs(text_content, file_ptr) != EOF)
			/* Using fputs to write text content */
			result = 1; /* Set return value to 1 on success */
	}

	fclose(file_ptr); /* Close file */

	return (result);
}

