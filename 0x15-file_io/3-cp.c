#include "main.h"

/**
* Checks if the specified file descriptor is valid and can be used for reading or writing.
* @fd: The file descriptor to check.
* @mode: The mode in which the file descriptor is used (either "reading" or "writing").
* @filename: The name of the file associated with the file descriptor (used for error messages).
* Return - void.
*/
void check_fd(int fd, const char *mode, const char *filename)
{
if (fd == -1)
{
fprintf(stderr, "Error: Can't %s from/to file '%s'\n", mode, filename);
exit(100);
}
}

/**
* copy_file - Copies the contents of one file to another.
* @from_filename: The name of the file to copy from.
* @to_filename: The name of the file to copy to.
* Return -  void.
*/
void copy_file(const char *from_filename, const char *to_filename)
{
const int buf_size = 1024;
char buf[buf_size];
ssize_t n_read, n_written;

/*Open the input file for reading.*/
int from_fd = open(from_filename, O_RDONLY);
check_fd(from_fd, "read", from_filename);

/*Open the output file for writing */
int to_fd = open(to_filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
check_fd(to_fd, "write", to_filename);

/*Read from the input file and write to the output file */
/*until there is nothing left to read.*/
while ((n_read = read(from_fd, buf, buf_size)) > 0)
{
n_written = write(to_fd, buf, n_read);
check_fd(n_written, "write", to_filename);
}
/**
* check_fd - closes file descriptor parameters
* 
*/
int err = close(from_fd);
check_fd(err, "close", from_filename);
err = close(to_fd);
check_fd(err, "close", to_filename);
}

/**
* Main - entry point
* @argc: The number of command-line arguments.
* @argv: An array of pointers to the command-line arguments.
* Return: 0 if successful, non-zero otherwise.
*/
int main(int argc, char *argv[])
{
// Check that the correct number of command-line arguments were provided.
if (argc != 3) {
fprintf(stderr, "Usage: %s <from_filename> <to_filename>\n", argv[0]);
exit(98);
}

// Copy the contents of the input file to the output file.
copy_file(argv[1], argv[2]);

// Exit successfully.
return (0);
}
