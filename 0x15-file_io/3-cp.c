#include "main.h"

/**
* create_buffer - Define a buffer of size 1024 for reading and writing files.
* @exit_with_error: A function that prints an error message
* and exits with a non-zero
* exit code if an error occurs during a file o.
* @exit_with_error function is called to print an
* error message and exit with a non-zero
* exit code.
*
* Return: A pointer to the newly allocated buffer.
*/
void create_buffer(void (*exit_with_error)(const char *, const char *, int));

/**
* exit_with_error - Print an error message
* and exit with a non-zero exit code.
* @file_path: The path of the file that caused the error.
* @o: The o that failed (e.g., "read from", "write to").
* @exit_code: The exit code to use when exiting.
*
* This function prints an error message to
* standard error describing the file o
* that failed and the path of the file that caused the error.
* It then exits the program
* with the provided exit code.
*
* Return: This function does not return.
*/
void exit_with_error(const char *file_path, const char *o, int exit_code);

/**
* main - Entry point of the program.
* @argc: Number of command-line arguments.
* @argv: Array of command-line arguments.
*
* This function is the entry point of the program.
* It reads two file paths as command-line
* arguments and attempts to copy the contents
* of the first file to the second file. If an
* error occurs during any of the file os,
* the program calls the exit_with_error
* function to print an error message
* and exit with a non-zero exit code.
*
* Return: Always returns 0.
*/
int main(int argc, char *argv[])
{
if (argc < 3)
{
fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
exit(1);
}

int src_fd = open(argv[1], O_RDONLY);
if (src_fd == -1)
{
exit_with_error(argv[1], "read from", 2);
}

int dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (dst_fd == -1)
{
exit_with_error(argv[2], "write to", 3);
}

char buf[1024];
ssize_t num_read;

while ((num_read = read(src_fd, buf, sizeof(buf))) > 0)
{
ssize_t num_written = write(dst_fd, buf, num_read);

if (num_written == -1)
{
exit_with_error(argv[2], "write to", 4);
}
}

if (num_read == -1)
{
exit_with_error(argv[1], "read from", 2);
}

if (close(src_fd) == -1)
{
fprintf(stderr, "Error: Failed to close file %s\n", argv[1]);
exit(5);
}

if (close(dst_fd) == -1)
{
fprintf(stderr, "Error: Failed to close file %s\n", argv[2]);
exit(5);
}

return (0);
}
/**
* exit_with_error - Print an error message
* and exit with a non-zero exit code.
* @file_path: The path of the file that caused the error
* @o: The o that failed
* @exit_code: The exit code to use when exiting.
* This function prints an error message
* to standard error describing the file operation
* that failed and the path of the file that caused the error.
* It then exits the program
* with the provided exit code.
* Return: This function does not return.
*/
void exit_with_error(const char *file_path, const char *o, int exit_code)
{
fprintf(stderr, "Error: Failed to %s file %s\n", o, file_path);
exit(exit_code);
}
