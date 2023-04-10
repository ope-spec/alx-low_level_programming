#include "main.h"

/**
 * create_buf - allocates 1024 bytes for a buffer
 * @f: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buf(char *f)
{
    char *buf;

    buf = malloc(BUF_SIZE);

    if (buf == NULL)
    {
        dprintf(STDERR_FILENO, "Erro: Can't write to %d\n", f);
        exit(99);
    }

    return (buf);
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
        dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd);
        exit(100);
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
    int file_from, file_to, num_read, num_written;
    char *buf;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp from file_to\n");
        exit(97);
    }

    buf = create_buf(argv[2]);
    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        free(buf);
        exit(98);
    }

    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (file_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        free(buf);
        exit(99);
    }

    num_read = read(file_from, buf, BUF_SIZE);
    while (num_read > 0)
    {
        num_written = write(file_to, buf, num_read);
        if (num_written == -1)
        {
            dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]);
            free(buf);
            close_file(file_from);
            close_file(file_to);
            exit(99);
        }
    }

    if (num_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
        free(buf);
        close_file(file_from);
        close_file(file_to);
        exit(98);
    }

    free(buf);
    close_file(file_from);
    close_file(file_to);

    return (0);
}