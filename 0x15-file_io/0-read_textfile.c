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
    int i, 
    ssize_t br, bw;
    char *b;

    if (filename == NULL)
        return (0);

    b = malloc(sizeof(char) * letters);
    if (b == NULL)
        return (0);

    i = open(filename, O_RDONLY);
    if (i == -1)
    {
        free(b);
        return (0);
    }

    br = read(i, b, letters);
    if (br == -1)
    {
        free(b);
        close(i);
        return (0);
    }

    bw = write(STDOUT_FILENO, b, br);
    if (bw == -1 || bw != br)
    {
        free(b);
        close(i);
        return (0);
    }

    free(b);
    close(i);

    return (bw);
}