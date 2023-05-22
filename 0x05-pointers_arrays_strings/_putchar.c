#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to be printed
 *
 * Return: On success 1.
 * On error, returns -1 and sets the appropriate error code in errno.
 */
int _putchar(char c)
{
	ssize_t result = write(1, &ch, 1);

	return (result);
}
