#ifndef MAIN_H
#define MAIN_H

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void exit_with_error(int err_code, const char *msg, ...);
void print_error(const char *msg);
int open_file(const char *filename, int flags, mode_t mode);
void close_file(int fd);
void copy_file(const char *file_from, const char *file_to);


#endif /* MAIN_H */

