#include "main.h"

/***
 * create_buffer - define buffer to be 1024
 * 
 * Return: a newly allocated buffer
 * 
***/

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int ff, ft, fc, nr, nw;
    char buf[BUFFER_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "The usage is cp file_from file_to\n");
        exit(97);
    }
    
    ff = open(argv[1], O_RDONLY);
    if (ff == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }
    
    ft = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (ft == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }

    while ((nr = read(ff, buf, BUFFER_SIZE)) > 0)
    {
        if ((nw = write(ft, buf, nr)) != nr)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            exit(99);
        }
        
    }
    
    if(nr == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    fc = close(ff);
    if(fc == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ff);
        exit(100);
    }

    fc = close(ft);
    if(fc == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ft);
        exit(100);
    }

    return 0;
    


}