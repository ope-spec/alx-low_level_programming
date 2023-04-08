#include "main.h"

/**
 * create_file - Creates a new file with the specified content.
 * @filename: name of the file to create
 * @text_content: content of the file to create
 *
 * Return: returns -1 when it fails
 *
 */
int create_file(const char *filename, char *text_content)
{
int fd;
	ssize_t len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (*(text_content + len))
			len++;
		len = write(fd, text_content, len);
		if (len == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
