#include "main.h"
#include <unistd.h>

/***
 * read_textfile - reads a text file and prints it to the POSIX standard output
 *
 * Description - function that reads a text file and prints it to the POSIX standard output.
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: If the file can not be opened or read, return 0. Return 0 if the @filename * is NULL.
 * Return 0 if write fails or does not write an expected amount of * bytes.
 * Otherwise, give back how many characters there are in total.
 ***/
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file_descriptor, bytes_read, bytes_written;
    char *buffer;

    if (!filename)
        return (0);

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * (letters + 1));
    if (!buffer)
        return (0);

    bytes_read = read(file_descriptor, buffer, letters);
    if (bytes_read == -1)
        return (0);

    buffer[bytes_read] = '\0';

    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_read != bytes_written)
        return (0);

    free(buffer);
    close(file_descriptor);

    return (bytes_read);
}