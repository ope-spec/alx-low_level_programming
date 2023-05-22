#include <unistd.h>

/**
 * _putchar - writes the character 'c' to the standard output (stdout)
 * @ch: character to be printed
 *
 * Return: On success 1.
 * On error, returns -1 and sets the appropriate error code in errno.
 */

int _putchar(char ch)
{
	ssize_t result = write(1, &ch, 1);

	return (result);
}
