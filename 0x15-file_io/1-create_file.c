#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file with the specified text content
 * @filename: Filename
 * @text_content: File content
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int fd, i = 0, bytes_written = 0;

if (filename == NULL)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
while (text_content[i] != '\0')
i++;

bytes_written = write(fd, text_content, i);
if (bytes_written == -1)
{
close(fd);
return (-1);
}
}

close(fd);

return (1);
}
