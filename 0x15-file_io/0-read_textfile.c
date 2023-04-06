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
    int fd,
    ssize_t br, bw;
    char *buffer;

    if (!filename)
    {
        return (0);
    }

    buffer = malloc(sizeof(char) * letters) 
    if (!buffer)
    {
        return (0);
    }

    fd = open(filename, O_RDONLY);
    br = read(fd, buffer, letters);
    bw = write(STDOUT_FILENO, buffer, br);

    if (fd == -1)
    {
        free(buffer);
        return (0);
    }

    if (br == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    if (bw == -1 || bw != br)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    free(buffer);
    close(fd);

    return (bw);
}