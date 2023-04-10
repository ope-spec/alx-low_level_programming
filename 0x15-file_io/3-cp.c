#include "main.h"

/**
 * main - copies the contents of one file to another.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Always returns zero (0), else exit.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, close_from, close_to;
	ssize_t read_bytes, write_bytes;
	char buf[BUFFER_SIZE];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
			exit(98);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	do {
		read_bytes = read(file_from, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
				exit(98);

		write_bytes = write(file_to, buf, read_bytes);
		if (write_bytes == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	} while (read_bytes > 0);

	close_from = close(file_from);
	if (close_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

	close_to = close(file_to);
	if (close_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

	return (0);
}
