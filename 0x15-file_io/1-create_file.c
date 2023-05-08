#include"main.h"

int create_file(const char *filename, char *text_content) {
	int fd;
	int len = 0;
	mode_t mode = S_IRUSR | S_IWUSR; /* rw------- */

	if (filename == NULL) {
		return -1;
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd == -1) {
		return -1;
	}

	if (text_content != NULL) {
		while (text_content[len]) {
			len++;
		}
		if (write(fd, text_content, len) == -1) {
			close(fd);
			return -1;
		}
	}

	close(fd);
	return 1;
}

