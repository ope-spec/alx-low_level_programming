#include "main.h"

/***
 * append_text_to_file - appends text
 * 
 * @filename - name of file in use
 * @text_content - content of file to be used
 * 
 * Return: return -1 when there is failure
 * 
***/
int append_text_to_file(const char *filename, char *text_content)
{
    int fd, br, len = 0;

    if (filename == NULL)
    {
        return (-1);
    }

    if (text_content != NULL)
    {
        while (text_content[len])
            len++;
    }

    fd = open(filename, O_CREAT | O_WRONLY | O_APPEND);
    br = write(fd, text_content, len);

    if (fd == -1)
    {
        return (-1);
    }

    if (text_content)
        if (br != len)
        {
            close(fd);
            return (-1);
        }

    close(fd);
    
    return (1);
}