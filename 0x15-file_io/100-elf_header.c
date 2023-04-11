#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>

void print_error(const char *error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
    exit(98);
}

void print_elf_header(const Elf64_Ehdr *elf_header) {
    printf("ELF Header:\n");
    printf("  Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\n");
    printf("  Class: ");
    switch (elf_header->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  Data: ");
    switch (elf_header->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  Version: %d\n", elf_header->e_ident[EI_VERSION]);
    printf("  OS/ABI: ");
    switch (elf_header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("Tru64 UNIX\n");
            break;
        case ELFOSABI_MODESTO:
            printf("Novell Modesto\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("OpenBSD\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("  Type: ");
    switch (elf_header->e_type) {
        case ET_NONE:
            printf("No file type\n");
            break;
        case ET_REL:
            printf("Relocatable file\n");
            break;
        case ET_EXEC:
            printf("Executable file\n");
            break;
        case ET_DYN:
            printf("Shared object file\n");
            break;
        case ET_CORE:
            printf("Core file\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    printf("  Entry point address: 0x%lx\n", elf_header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    const char *filename = argv[1

