int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buf[BUF_SIZE];
	mode_t file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; /* rw-rw-r-- permissions */

	/* Check if the correct number of arguments is provided */
	if (argc != 3)
		exit_with_error(97, "Usage: cp file_from file_to");

	/* Open file_from for reading */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		exit_with_error(98, "Can't read from file %s", argv[1]);

	/* Open file_to for writing, with truncate and create flags */
	fd_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, file_mode);
	if (fd_to == -1)
		exit_with_error(99, "Can't write to file %s", argv[2]);

	/* Copy content from file_from to file_to */
	while ((bytes_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buf, bytes_read);
		if (bytes_written == -1)
			exit_with_error(99, "Can't write to file %s", argv[2]);
	}

	if (bytes_read == -1)
		exit_with_error(98, "Can't read from file %s", argv[1]);

	/* Close file descriptors */
	if (close(fd_from) == -1)
		exit_with_error(100, "Can't close fd %d", fd_from);

	if (close(fd_to) == -1)
		exit_with_error(100, "Can't close fd %d", fd_to);

	return 0;
}
