#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFSIZE 1024

void read_elf_header(int fd, Elf32_Ehdr *header);
void print_elf_header(const Elf32_Ehdr *header);
void validate_elf_header(const Elf32_Ehdr *header);
void print_error(const char *message);

/**
 * main - Entry point for ELF header reader program
 * @argc: Number of arguments passed to program
 * @argv: Array of pointers to argument strings
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	/* char buf[BUFSIZE]; */
	Elf32_Ehdr header;

	/* Check command-line arguments */
	if (argc != 2)
	{
		print_error("usage: elf_header elf_filename");
		exit(98);
	}

	/* Open the ELF file */
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		print_error("cannot open file");
		exit(98);
	}

	/* Read the ELF header */
	read_elf_header(fd, &header);

	/* Validate the ELF header */
	validate_elf_header(&header);

	/* Print the ELF header */
	print_elf_header(&header);

	/* Close the file */
	close(fd);

	return (0);
}
/*
 * print_error - prints an error message to stderr
 *
 * @message: the error message to print
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
}
/*
 * validate_elf_header - validates the ELF header and prints an error message
 * if the file is not a valid ELF file
 *
 * @header: a pointer to the ELF header structure
 */
void validate_elf_header(const Elf32_Ehdr *header)
{
	/* Check the magic number */
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
			header->e_ident[EI_MAG1] != ELFMAG1 ||
			header->e_ident[EI_MAG2] != ELFMAG2 ||
			header->e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: not an ELF file\n");
		exit(98);
	}

	/* Check the ELF class */
	if (header->e_ident[EI_CLASS] != ELFCLASS32)
	{
		fprintf(stderr, "Error: unsupported ELF class\n");
		exit(98);
	}

	/* Check the ELF data encoding */
	if (header->e_ident[EI_DATA] != ELFDATA2LSB
			&& header->e_ident[EI_DATA] != ELFDATA2MSB)
	{
		fprintf(stderr, "Error: unsupported ELF data encoding\n");
		exit(98);
	}

	/* Check the ELF version */
	if (header->e_ident[EI_VERSION] != EV_CURRENT)
	{
		fprintf(stderr, "Error: unsupported ELF version\n");
		exit(98);
	}

	/* Check the ELF type */
	if (header->e_type != ET_NONE && header->e_type != ET_REL
			&& header->e_type != ET_EXEC &&
			header->e_type != ET_DYN && header->e_type != ET_CORE)
	{
		fprintf(stderr, "Error: unsupported ELF type\n");
		exit(98);
	}

	/* Check the machine architecture */
	if (header->e_machine != EM_386)
	{
		fprintf(stderr, "Error: unsupported machine architecture\n");
		exit(98);
	}
}

/*
 * print_elf_header - prints the ELF header information to the standard output
 * in the required format
 *
 * @header: a pointer to the ELF header structure
 */
void print_elf_header(const Elf32_Ehdr *header)
{
	int i;

	/* Print the magic number */
	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	/* Print the class */
	printf("Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
	/* Print the data encoding */
	printf("Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
	/* Print the ELF version */
	printf("Version:            %d\n", header->e_ident[EI_VERSION]);
	/* Print the OS/ABI */
	printf("OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V ABI\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX ABI\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD ABI\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux ABI\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris ABI\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD ABI\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
	/* Print the ABI version */
	printf("ABI Version:             %d\n", header->e_ident[EI_ABIVERSION]);
	/* Print the ELF type */
	printf("Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
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
			printf("<unknown>\n");
			break;
	}
	/* Print the entry point address */
	printf("Entry point address:               0x%x\n", header->e_entry);
}

/*
 * read_elf_header - reads the ELF header information
 * from the file descriptor fd
 * and stores it in the header variable
 *
 * @fd: the file descriptor of the ELF file
 * @header: a pointer to the ELF header structure
 */
void read_elf_header(int fd, Elf32_Ehdr *header)
{
	ssize_t n = 0;

	/* Read the ELF header from the file */
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		perror("lseek");
		exit(98);
	}

	n = read(fd, header, sizeof(*header));
	if (n < 0)
	{
		perror("read");
		exit(98);
	}

	/* Check that the ELF header is the correct size */
	if (n != sizeof(*header))
	{
		fprintf(stderr, "Error: ELF header size mismatch\n");
		exit(98);
	}
}


