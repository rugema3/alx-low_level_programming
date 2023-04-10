#include <fcntl.h>    /* For open() */
#include <unistd.h>   /* For read(), write()*/
#include <stdio.h>    /* For perror() */
#include <stdlib.h>   /* For malloc(), free() */


/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 *
 * @filename: The name of the file to be read.
 * @letters: The number of letters to be read and printed.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
  int fd;             /*File descriptor*/
  ssize_t n_read;     /* Number of bytes read*/
  char *buffer;       /* Buffer to hold read data*/
  ssize_t n_written; /* Number of bytes written*/
  ssize_t total_written = 0; /* Total number of bytes written*/
  ssize_t remaining_letters = letters; /* Remaining letters to read and print */

  if (filename == NULL) /* Check if filename is NULL*/
    return 0;

  /* Open the file in read-only mode*/
  fd = open(filename, O_RDONLY);
  if (fd == -1) {
    perror("read_textfile: open");
    return 0;
  }

  /* Allocate memory for the buffer*/
  buffer = malloc(letters);
  if (buffer == NULL) {
    perror("read_textfile: malloc");
    close(fd); /* Close the file descriptor before returning*/
    return 0;
  }

  /* Read data from the file*/
  n_read = read(fd, buffer, letters);
  if (n_read == -1) {
    perror("read_textfile: read");
    close(fd); /* Close the file descriptor before returning*/
    free(buffer); /* Free the allocated memory before returning*/
    return 0;
  }

  /* Write data to stdout*/
  while (n_read > 0 && remaining_letters > 0) {
    /* Write data to stdout*/
    n_written = write(STDOUT_FILENO, buffer + total_written, n_read);
    if (n_written <= 0) {
      perror("read_textfile: write");
      close(fd); /* Close the file descriptor before returning*/
      free(buffer); /* Free the allocated memory before returning*/
      return 0;
    }

    total_written += n_written;
    remaining_letters -= n_written;
    n_read -= n_written;
  }

  close(fd); /* Close the file descriptor*/
  free(buffer); /* Free the allocated memory*/

  return total_written; /* Return the total number of bytes read and printed */
}

