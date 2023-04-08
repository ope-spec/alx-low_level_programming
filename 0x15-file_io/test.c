int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        exit_with_error(argv[1], "read from", 2);
    }

    int dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        exit_with_error(argv[2], "write to", 3);
    }

    char buf[1024];
    ssize_t num_read;

    while ((num_read = read(src_fd, buf, sizeof(buf))) > 0) {
        ssize_t num_written = write(dst_fd, buf, num_read);
        if (num_written == -1) {
            exit_with_error(argv[2], "write to", 4);
        }
    }

    if (num_read == -1) {
        exit_with_error(argv[1], "read from", 2);
    }

    if (close(src_fd) == -1) {
        dprintf(STDERR_FILENO, "Error: Failed to close file %s\n", argv[1]);
        exit(5);
    }

    if (close(dst_fd) == -1) {
        dprintf(STDERR_FILENO, "Error: Failed to close file %s\n", argv[2]);
        exit(5);
    }

    return 0;
}