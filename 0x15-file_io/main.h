#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define EI_NIDENT 16


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * error_exit - print an error message to stderr and exit with a given code
 * @code: the exit code
 * @message: the error message format string
 * @...: the arguments for the format string
 */
void error_exit(int code, const char *message, ...) __attribute__((noreturn));
void error_exit(int code, const char *message, ...)
{
  va_list args;

  va_start(args, message);
  dprintf(STDERR_FILENO, "Error: ");
  vdprintf(STDERR_FILENO, message, args);
  dprintf(STDERR_FILENO, "\n");
  va_end(args);

  exit(code);
}

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void print_hex(const unsigned char *buf, size_t size);
void print_elf_header(const Elf64_Ehdr *hdr);
#endif
