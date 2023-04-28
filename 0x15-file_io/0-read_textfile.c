#include <stdio.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: Name of the text file to be read
 * @letters: Number of letters to be read and printed
 *
 * Return: Actual number of letters read and printed,
 * or 0 if file cannot be opened or read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fh;
	char c;
	size_t count = 0;

	fh = fopen(filename, "r");
	if (fh != NULL)
	{
		while ((c = fgetc(fh)) != EOF && letters > 0)
		{
			count++;
			fputc(c, stderr); /* Print to stderr instead of stdout */
			letters--;
		}
		fclose(fh);
	}
	else
		return (0);
	return (count);
}

