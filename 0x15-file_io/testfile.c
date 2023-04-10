#include "main.h"

/**
 * check_error - checks if files can be opened.
 * @file_from: source of copied file.
 * @file_to: destination of copied file.
 * @argv: arguments vector.
 * Return: no return.
 */
void check_error(int file_from, int file_to, char *argv[])
{
    if (file_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }
    if (file_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }
}

/**
 * main - program that copies from one file to another.
 * @argc: Arguments count parameter.
 * @argv: arguments vector parameter.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    int file_from, file_to, close_file;
    ssize_t read_bytes, write_bytes;
    char buf[1024];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
        exit(97);
    }

    file_from = open(argv[1], O_RDONLY);
    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
    check_error(file_from, file_to, argv);

    read_bytes = 1024;
    while (read_bytes == 1024)
    {
        read_bytes = read(file_from, buf, 1024);
        if (read_bytes == -1)
            check_error(-1, 0, argv);
        write_bytes = write(file_to, buf, read_bytes);
        if (write_bytes == -1)
            check_error(-1, 0, argv);
    }

    close_file = close(file_from);
    if (close_file == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
        exit(100);
    }

    close_file = close(file_to);
    if (close_file == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
        exit(100);
    }

    return (0);
}
