#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - program that displays the ELF header at the start of an ELF file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd, i;
	ssize_t bytes_read;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (98);
	}

	bytes_read = read(fd, &ehdr, sizeof(ehdr));
	if (bytes_read != sizeof(ehdr))
	{
		perror("Error reading ELF header");
		close(fd);
		return (98);
	}
	if (ehdr.e_ident[EI_MAG0] != ELFMAG0 || ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
			ehdr.e_ident[EI_MAG2] != ELFMAG2 || ehdr.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		return (98);
	}
	/* Display the ELF header */
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr.e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n",
			ehdr.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
			ehdr.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", ehdr.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", ehdr.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Other");
	printf("  ABI Version:                       %d\n", ehdr.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			ehdr.e_type == ET_EXEC ? "EXEC (Executable file)" : "Other");
	printf("  Entry point address:               0x%lx\n", ehdr.e_entry);
	close(fd);
	return (0);
}

