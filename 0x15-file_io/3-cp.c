#include "main.h"

/***
 * create_buffer - define buffer to be 1024
 * 
 * Return: a newly allocated buffer
 * 
***/

int main(int argc, char *argv[]) {
    int file_from, file_to;
    ssize_t bytes_read, bytes_written;
    char buffer[1024];

    if (argc != 3) {
        printf("Usage: cp file_from file_to\n");
        exit(EXIT_FAILURE);
    }

    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1) {
        printf("Error: Can't read from file %s. %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (file_to == -1) {
        printf("Error: Can't write to %s. %s\n", argv[2], strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = read(file_from, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(file_to, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            printf("Error: Failed to write to %s. %s\n", argv[2], strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        printf("Error: Failed to read from %s. %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (close(file_from) == -1) {
        printf("Error: Can't close file descriptor for %s. %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (close(file_to) == -1) {
        printf("Error: Can't close file descriptor for %s. %s\n", argv[2], strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}
