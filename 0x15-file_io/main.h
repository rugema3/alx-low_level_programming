#ifndef MAIN_H
#define MAIN_H

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void exit_with_error(int err_code, const char *msg, ...);
void print_error(const char *msg);

#endif /* MAIN_H */

