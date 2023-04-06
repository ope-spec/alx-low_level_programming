#include "main.h"

/***
 * create_file - creates a file
 *
 * @filename - name of the file to create
 * @text_content - content of the file to create
 *
 * Return - returns -1 when it fails
 *
 ***/
int create_file(const char *filename, char *text_content)
{
    int fd, p, len = 0;

    if (!filename)
    {
        return (-1);
    }

    if (text_content != NULL)
    {
        while (text_content[len])
            len++;
    }

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    p = write(fd, text_content, len);

    if (fd == -1)
    {
        return (-1);
    }

    if (text_content)
        if (p != len)
        {
            close(fd);
            return (-1);
        }

    close(fd);
    
    return (1);
}