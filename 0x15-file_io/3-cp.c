#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void exitWithError(int code, char *filename) {
    switch (code) {
        case 97:
            dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
            break;
        case 98:
            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
            break;
        case 99:
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
            break;
        case 100:
            dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", filename);
            break;
    }
    exit(code);
}

void copyFile(char *fileFrom, char *fileTo) {
    int fdFrom, fdTo, readBytes, writeBytes, closeFd;

    fdFrom = open(fileFrom, O_RDONLY);
    if (fdFrom == -1) {
        exitWithError(98, fileFrom);
    }

    fdTo = open(fileTo, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fdTo == -1) {
        exitWithError(99, fileTo);
    }

    char buffer[BUFFER_SIZE];
    while ((readBytes = read(fdFrom, buffer, BUFFER_SIZE)) > 0) {
        if ((writeBytes = write(fdTo, buffer, readBytes)) != readBytes) {
            exitWithError(99, fileTo);
        }
    }
    if (readBytes == -1) {
        exitWithError(98, fileFrom);
    }

    closeFd = close(fdFrom);
    if (closeFd == -1) {
        exitWithError(100, fileFrom);
    }

    closeFd = close(fdTo);
    if (closeFd == -1) {
        exitWithError(100, fileTo);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        exitWithError(97, "");
    }

    copyFile(argv[1], argv[2]);

    return 0;
}
