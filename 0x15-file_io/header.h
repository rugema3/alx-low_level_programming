#ifndef ELF_HEADER_H
#define ELF_HEADER_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ELF_MAGIC_NUMBER "\x7F""ELF"

typedef struct {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

void display_elf_header(const char* filename);
void read_elf_header(int fd, Elf64_Ehdr* elf_header);
void check_elf_file(const Elf64_Ehdr* elf_header, const char* filename);
void display_elf_magic(const Elf64_Ehdr* elf_header);
void display_elf_class(const Elf64_Ehdr* elf_header);
void display_elf_data(const Elf64_Ehdr* elf_header);
void display_elf_version(const Elf64_Ehdr* elf_header);
void display_elf_osabi(const Elf64_Ehdr* elf_header);

#endif /* ELF_HEADER_H */

