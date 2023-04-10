#include "main.h"

#define BUFFER_SIZE 1024

/**
* copy_file - copies the content of a file to another file
* @src: source file path
* @dest: destination file path
*
* Return: On success, return 0. On error, return a non-zero value
*/
int copy_file(const char *src, const char *dest)
{
int src_fd, dest_fd, bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

src_fd = open(src, O_RDONLY);
if (src_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
return (98);
}

dest_fd = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (dest_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
close(src_fd);
return (99);
}

while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(dest_fd, buffer, bytes_read);
if (bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
close(src_fd);
close(dest_fd);
return (99);
}
}

if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
close(src_fd);
close(dest_fd);
return (98);
}

if (close(src_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
return (100);
}

if (close(dest_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
return (100);
}

return (0);
}

/**
* main - entry point
* @argc: argument count
* @argv: argument vector
*
* Return: On success, return 0. On error, return a non-zero value
*/
int main(int argc, char *argv[])
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
return (97);
}

return (copy_file(argv[1], argv[2]));
}
