#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - prints error message and exits
 * @msg: error message to print
 *
 * Return: void
 */
void print_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}
/**
 * print_magic - prints ELF magic number
 * @magic: ELF magic number
 *
 * Return: void
 */
void print_magic(const unsigned char *magic)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", magic[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}
/**
 * print_class - prints ELF class
 * @elf_class: ELF class
 *
 * Return: void
 */
void print_class(uint8_t elf_class)
{
	printf("  Class:                             %s\n",
			elf_class == ELFCLASS32 ? "ELF32" : "ELF64");
}
/**
 * print_data - prints ELF data encoding
 * @elf_data: ELF data encoding
 *
 * Return: void
 */
void print_data(uint8_t elf_data)
{
	printf("  Data:                              %s\n",
			elf_data == ELFDATA2LSB ? "2's complement, little endian" :
			"2's complement, big endian");
}
/**
 * print_version - prints ELF version
 * @elf_version: ELF version
 *
 * Return: void
 */
void print_version(uint8_t elf_version)
{
	printf("  Version:                           %d (current)\n", elf_version);
}
/**
 * print_osabi - prints ELF OS/ABI
 * @elf_osabi: ELF OS/ABI
 *
 * Return: void
 */
void print_osabi(uint8_t elf_osabi)
{
	printf("  OS/ABI:                            ");
	switch (elf_osabi)
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;

		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %d>\n", elf_osabi);
			break;
	}
}
/**
 * print_type - prints ELF file type
 * @elf_type: ELF file type
 *
 * Return: void
 */
void print_type(uint16_t elf_type)
{
	printf("  Type:                              ");
	switch (elf_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %d>\n", elf_type);
			break;
	}
}
/**
 * print_entry - prints ELF entry point address
 * @elf_entry: ELF entry point address
 *
 * Return: void
 */
void print_entry(uint64_t elf_entry)
{
	printf("  Entry point address:               0x%lx\n", elf_entry);
}
/**
 * print_header - prints ELF header information
 * @filename: filename of ELF file to read
 *
 * Return: void
 */
void print_header(const char *filename)
{
	int fd;
	Elf64_Ehdr ehdr;
	Elf32_Ehdr ehdr32;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Could not open file");

	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Could not seek to beginning of file");

	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
		print_error("Could not read ELF header");

	if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0)
		print_error("File is not an ELF file");

	if (ehdr.e_ident[EI_CLASS] == ELFCLASS32) {
		if (lseek(fd, 0, SEEK_SET) == -1)
			print_error("Could not seek to beginning of file");

		if (read(fd, &ehdr32, sizeof(ehdr32)) != sizeof(ehdr32))
			print_error("Could not read ELF header");

		if (memcmp(ehdr32.e_ident, ELFMAG, SELFMAG) != 0)
			print_error("File is not an ELF file");

		printf("ELF Header:\n");
		print_magic(ehdr32.e_ident);
		print_class(ehdr32.e_ident[EI_CLASS]);
		print_data(ehdr32.e_ident[EI_DATA]);
		print_version(ehdr32.e_ident[EI_VERSION]);
		print_osabi(ehdr32.e_ident[EI_OSABI]);
		printf("  ABI Version:                       %d\n", ehdr32.e_ident[EI_ABIVERSION]);
		print_type(ehdr32.e_type);
		print_entry(ehdr32.e_entry);
	} else {
		printf("ELF Header:\n");
		print_magic(ehdr.e_ident);
		print_class(ehdr.e_ident[EI_CLASS]);
		print_data(ehdr.e_ident[EI_DATA]);
		print_version(ehdr.e_ident[EI_VERSION]);
		print_osabi(ehdr.e_ident[EI_OSABI]);
		printf("  ABI Version:                       %d\n", ehdr.e_ident[EI_ABIVERSION]);
		print_type(ehdr.e_type);
		print_entry(ehdr.e_entry);
	}

	close(fd);
}
/**
 * print_usage_error - prints a usage error message to stderr
 */
void print_usage_error(void)
{
    fprintf(stderr, "Usage: elf_header <filename>\n");
    exit(98);
}

/**
 * main - prints ELF header information
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		print_usage_error();

	print_header(argv[1]);

	return (0);
}

