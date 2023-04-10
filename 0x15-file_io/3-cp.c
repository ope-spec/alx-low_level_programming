#include "main.h"

#define BUFFER_SIZE 1024
/**
 * check_error - checks if files can be opened
 * and prints an error message.
 * 
 * @file_from: the file descriptor of the source file.
 * @file_to: the file descriptor of the destination file.
 * @file_from_path: the path of the source file.
 * @file_to_path: the path of the destination file.
 * 
 * Return: zero (Success)
 */
void check_error(int file_from, int file_to, char *file_from_path, char *file_to_path)
{
    if (file_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from_path);
        exit(98);
    }
    if (file_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to_path);
        exit(99);
    }
}

/**
 * main - copies the contents of one file to another.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return - Always returns zero (0).
 */
int main(int argc, char *argv[])
{
    int file_from, file_to, close_file;
    ssize_t read_bytes, write_bytes;
    char buf[BUFFER_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    file_from = open(argv[1], O_RDONLY);
    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
    check_error(file_from, file_to, argv[1], argv[2]);

    while ((read_bytes = read(file_from, buf, BUFFER_SIZE)) > 0)
    {
        write_bytes = write(file_to, buf, read_bytes);
        if (write_bytes == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            exit(99);
        }
        
    }

    if (read_bytes == -1)
    {
        check_error(-1, file_from, argv[1], argv[2]);
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
