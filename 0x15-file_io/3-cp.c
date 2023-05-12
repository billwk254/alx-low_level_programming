#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * main - program entry point
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 * Return: 0 on success, or a non-zero value on failure
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to, rd, wr;
char buffer[BUFFER_SIZE];
mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

if (argc != 3)
error_exit(97, "Usage: cp file_from file_to");

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
error_exit(98, "Can't read from file %s", argv[1]);

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
if (fd_to == -1)
error_exit(99, "Can't write to %s", argv[2]);

while ((rd = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
wr = write(fd_to, buffer, rd);
if (wr == -1)
error_exit(99, "Can't write to %s", argv[2]);
if (wr != rd)
error_exit(99, "Short write to %s", argv[2]);
}

if (rd == -1)
error_exit(98, "Can't read from file %s", argv[1]);

if (close(fd_from) == -1)
error_exit(100, "Can't close fd %d", fd_from);

if (close(fd_to) == -1)
error_exit(100, "Can't close fd %d", fd_to);

return (0);
}
