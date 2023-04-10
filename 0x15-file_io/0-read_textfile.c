what's wrong with this code:
#include<stdio.h>
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
	/**
	 * fh is a file handler
	 * r means the file is in readmode. We wanna read the file
	 */

	if (fh != NULL)
	{
		while ((c = fgetc(fh)) != EOF && letters > 0)
		{
			count++;/*increament the count each time you go through the loop*/
			putchar(c);
			letters--; /*decrement letters to be read*/
		}
		fclose(fh);
	}
	else
		return (0);
	return (count);
}
