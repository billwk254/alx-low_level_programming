#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>


void print_hex(const unsigned char *buf, size_t size)
{
  size_t i;

  for (i = 0; i < size; i++) {
    printf("%02x ", buf[i]);
  }

  putchar('\n');
}

void print_elf_header(const Elf64_Ehdr *hdr)
{
  printf("ELF Header:\n");
  printf("  Magic:   ");
  print_hex(hdr->e_ident, EI_NIDENT);
  printf("  Class:                             %s\n", hdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
  printf("  Data:                              %s\n", hdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
  printf("  Version:                           %d (current)\n", hdr->e_ident[EI_VERSION]);
  printf("  OS/ABI:                            %s\n", hdr->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "unknown");
  printf("  ABI Version:                       %d\n", hdr->e_ident[EI_ABIVERSION]);
  printf("  Type:                              %s\n", hdr->e_type == ET_NONE ? "NONE (Unknown Type)" :
	 hdr->e_type == ET_REL ? "REL (Relocatable file)" :
	 hdr->e_type == ET_EXEC ? "EXEC (Executable file)" :
	 hdr->e_type == ET_DYN ? "DYN (Shared object file)" :
	 hdr->e_type == ET_CORE ? "CORE (Core file)" :
	 "unknown");
  printf("  Entry point address:               %lx\n", hdr->e_entry);
}

int main(int argc, char **argv)
{
  int fd;
  Elf64_Ehdr hdr;

  if (argc != 2) {
    dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
    return 98;
  }

  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    dprintf(STDERR_FILENO, "Error: could not open file %s\n", argv[1]);
    return 98;
  }

  if (read(fd, &hdr, sizeof(hdr)) != sizeof(hdr)) {
    dprintf(STDERR_FILENO, "Error: could not read ELF header of file %s\n", argv[1]);
    close(fd);
    return 98;
  }

  if (hdr.e_ident[EI_MAG0] != ELFMAG0 || hdr.e_ident[EI_MAG1] != ELFMAG1 ||
      hdr.e_ident[EI_MAG2] != ELFMAG2 || hdr.e_ident[EI_MAG3] != ELFMAG3) {
    dprintf(STDERR_FILENO, "Error: file %s is not an ELF file\n", argv[1]);
    close(fd);
    return 98;
  }

  print_elf_header(&hdr);

  close(fd);

  return 0;
}
