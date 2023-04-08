#include "main.h"

/***
 * create_buffer - define buffer to be 1024
 * 
 * Return: a newly allocated buffer
 * 
***/

#define BUFFER_SIZE 1024

/**
 * error - function that prints error messages and exits with a status code
 * @exit_code: the exit status code
 * @message: the error message to print
 */
void error(int exit_code, char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}

/**
 * main - program that copies the content of a file to another file
 * @argc: the number of arguments
 * @argv: the array of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, rd, wr, close_status;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error(98, "Error: Can't read from file %s", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error(99, "Error: Can't write to %s", argv[2]);

	while ((rd = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr != rd)
			error(99, "Error: Can't write to %s", argv[2]);
	}

	if (rd == -1)
		error(98, "Error: Can't read from file %s", argv[1]);

	close_status = close(fd_from);
	if (close_status == -1)
		error(100, "Error: Can't close fd %d", fd_from);

	close_status = close(fd_to);
	if (close_status == -1)
		error(100, "Error: Can't close fd %d", fd_to);

	return (0);
}
