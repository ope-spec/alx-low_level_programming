#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024
char *create_buf(char *f);

/**
* error_file - checks if files can be opened.
* @file_from: file_from.
* @file_to: file_to.
* @argv: arguments vector.
* Return: no return.
*/
void close_file(int fd);

char *create_buf(char *f)
{
char *buf;

buf = malloc(sizeof(char) * BUF_SIZE);

if (buf == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", f);
exit(99);
}

return (buf);
}


void close_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* main - check the code for ALX students.
* @argc: number of arguments.
* @argv: arguments vector.
* Return: Always 0.
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
close_file(file_from);
exit(99);
}

while ((num_read = read(file_from, buf, BUF_SIZE)) > 0)
{
num_written = write(file_to, buf, num_read);
if (num_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buf);
close_file(file_from);
close_file(file_to);
exit(99);
}
}

if (num_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
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
