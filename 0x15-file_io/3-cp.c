#include "main.h"
#include <stdlib.h>

/**
 * create_buf - allocates 1024 bytes for a buffer
 * @f: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(size_t size) {
    char *buffer = malloc(size);

    if (buffer == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    return buffer;
}

/**
 * close_file - closes fd
 *
 * @fd: File descriptor to be closed.
 */
void close_file(int fd)
{
    if (close(fd) == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

/**
 * Main - copies the contents of one file to another
 *
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return - Always returns zero (0).
 */
int main(int argc, char *argv[])
{
    int input_fd, output_fd;
    ssize_t num_read, num_written;
    char *buffer;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    buffer = allocate_buffer(BUFFER_SIZE);

    input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1)
    {
        perror("open");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (output_fd == -1)
    {
        perror("open");
        free(buffer);
        close_file(input_fd);
        exit(EXIT_FAILURE);
    }

    while ((num_read = read(input_fd, buffer, BUFFER_SIZE)) > 0)
    {
        num_written = write(output_fd, buffer, num_read);
        if (num_written == -1)
        {
            perror("write");
            free(buffer);
            close_file(input_fd);
            close_file(output_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (num_read == -1)
    {
        perror("read");
        free(buffer);
        close_file(input_fd);
        close_file(output_fd);
        exit(EXIT_FAILURE);
    }

    free(buffer);
    close_file(input_fd);
    close_file(output_fd);

    return EXIT_SUCCESS;
}
