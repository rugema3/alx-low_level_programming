
#include "header.h"

/**
 * read_elf_header - reads the ELF header from the given file descriptor
 * @fd: the file descriptor of the ELF file
 * @elf_header: a pointer to the ELF header struct to populate
 *
 * This function reads the ELF header from the given file descriptor into the
 * provided ELF header struct. If an error occurs, an error message is printed
 * to standard error and the program exits with status code 98.
 */
void read_elf_header(int fd, Elf64_Ehdr* elf_header) {
	if (read(fd, elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
		fprintf(stderr, "Error: cannot read ELF header\n");
		exit(98);
	}
}
/**
 * check_elf_file - checks if the given file is a valid ELF file
 * @elf_header: a pointer to the ELF header struct to check
 * @filename: the name of the file being checked
 *
 * This function checks if the given file is a valid ELF file by comparing the
 * magic number in the ELF header with the expected magic number. If the file
 * is not a valid ELF file, an error message is printed to standard error and
 * the program exits with status code 98.
 */
void check_elf_file(const Elf64_Ehdr* elf_header, const char* filename) {
	if (elf_header->e_ident[0] != ELF_MAGIC_NUMBER[0] ||
			elf_header->e_ident[1] != ELF_MAGIC_NUMBER[1] ||
			elf_header->e_ident[2] != ELF_MAGIC_NUMBER[2] ||
			elf_header->e_ident[3] != ELF_MAGIC_NUMBER[3]) {
		fprintf(stderr, "Error: file '%s' is not an ELF file\n", filename);
		exit(98);
	}
}

/**
 * display_elf_magic - displays the magic number of the given ELF header
 * @elf_header: a pointer to the ELF header struct to display
 *
 * This function displays the magic number of the given ELF header in the
 * format "Magic:   XX XX XX XX ...", where XX is the hexadecimal value of each
 * byte of the magic number.
 */
void display_elf_magic(const Elf64_Ehdr* elf_header) {
	printf("  Magic:   ");
	for (int i = 0; i < sizeof(elf_header->e_ident); i++) {
		printf("%02x ", elf_header->e_ident[i]);
	}
	printf("\n");
}
/**
 * display_elf_class - displays the class of the given ELF header
 * @elf_header: a pointer to the ELF header struct to display
 *
 * This function displays the class of the given ELF header (either ELF32 or
 * ELF64) in the format "Class:                             ELFXX".
 */
void display_elf_class(const Elf64_Ehdr* elf_header) {
	printf("  Class:                             %s\n", elf_header->e_ident[4] == 1 ? "ELF64" : "unknown");
}

/**
 * display_elf_data - Display the data encoding of the ELF file.
 * @elf_header: Pointer to the ELF header structure.
 */
void display_elf_data(const Elf64_Ehdr* elf_header) {
	printf("  Data:                              %s\n", elf_header->e_ident[5] == 1 ? "2's complement, little endian" : "unknown");
}

/**
 * display_elf_version - Display the version of the ELF file.
 * @elf_header: Pointer to the ELF header structure.
 */
void display_elf_version(const Elf64_Ehdr* elf_header) {
	printf("  Version:                           %d%s\n", elf_header->e_ident[6], elf_header->e_ident[6] == 1 ? " (current)" : "");
}

/**
 * display_elf_osabi - Display the operating system and ABI of the ELF file.
 * @elf_header: Pointer to the ELF header structure.
 */
void display_elf_osabi(const Elf64_Ehdr* elf_header) {
	printf("  OS/ABI:                            ");
	switch (elf_header->e_ident[7]) {
		case 0: printf("UNIX System V ABI"); break;
		case 1: printf("HP-UX ABI"); break;
		case 2: printf("NetBSD ABI"); break;
		case 3: printf("Linux ABI"); break;
		case 6: printf("Solaris ABI"); break;
		case 7: printf("AIX ABI"); break;
		case 8: printf("IRIX ABI"); break;
		case 9: printf("FreeBSD ABI"); break;
		case 10: printf("Tru64 UNIX ABI"); break;
		case 11: printf("Novell Modesto ABI"); break;
		case 12: printf("OpenBSD ABI"); break;
		case 13: printf("OpenVMS ABI"); break;
		case 14: printf("HP Non-Stop Kernel ABI"); break;
		case 15: printf("Amiga Research OS ABI"); break;
		case 16: printf("Solaris-like ABI"); break;
		case 64: printf("ARM EABI"); break;
		case 97: printf("ARM"); break;
		case 255: printf("Standalone (embedded) ABI"); break;
		default: printf("unknown"); break;
	}
	printf("\n");
}

