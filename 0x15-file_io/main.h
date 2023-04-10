#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>  // for exit()
#include <fcntl.h>   // for open(), O_RDONLY, O_CREAT, O_WRONLY, O_TRUNC, O_APPEND
#include <unistd.h>  // for read(), write(), close()
#define BUFFER_SIZE 1024

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);

#endif /* MAIN_H */