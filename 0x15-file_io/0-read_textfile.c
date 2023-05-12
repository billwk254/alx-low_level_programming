#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: number of bytes it could read and print, 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd, bytes_written;
ssize_t bytes_read;
char *buf;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
close(fd);
return (0);
}

bytes_read = read(fd, buf, letters);
if (bytes_read == -1)
{
close(fd);
free(buf);
return (0);
}

bytes_written = write(STDOUT_FILENO, buf, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
close(fd);
free(buf);
return (0);
}

close(fd);
free(buf);

return (bytes_written);
}
