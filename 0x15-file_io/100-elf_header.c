#include "main.h"
#include <elf.h>

/**
 * printClass - prints class
 *
 * @header: Elf64_Ehdr struct
 */
void printClass(Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	if (header->e_ident[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
}

/**
 * printData - print type of how data is organized
 *
 * @header: Elf64_Ehdr struct
 */
void printData(Elf64_Ehdr *header)
{
	printf("  Data:                              ");

	if (header->e_ident[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
}

/**
 * printOS - prints name of the OS
 *
 * @header: Elf64_Ehdr struct
 */
void printOS(Elf64_Ehdr *header)
{
	printf("  OS/ABI:                            ");

	if (header->e_ident[EI_OSABI] == ELFOSABI_NONE)
		printf("UNIX - System V\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");

}

/**
 * printType - prints type of file
 *
 * @header: Elf64_Ehdr struct
 */
void printType(Elf64_Ehdr *header)
{
	printf("  Type:                              ");
	if (header->e_type == 0)
		printf("NONE (Unknown type)\n");
	else if (header->e_type == 1)
		printf("REL (Relocatable file)\n");
	else if (header->e_type == 2)
		printf("EXEC (Executable file)\n");
	else if (header->e_type == 3)
		printf("DYN (Shared object file)\n");
	else if (header->e_type == 4)
		printf("CORE (Core file)\n");
}

/**
 * printEntry - Prints the entry point of an ELF header.
 *
 * @header: Elf64_Ehdr struct
 */
void printEntry(Elf64_Ehdr *header)
{
	printf("  Entry point address:               ");

	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		header->e_entry = ((header->e_entry << 8) & 0xFF00FF00) |
			  ((header->e_entry >> 8) & 0xFF00FF);
		header->e_entry = (header->e_entry << 16) | (header->e_entry >> 16);
	}

	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)header->e_entry);

	else
		printf("%#lx\n", header->e_entry);
}
/**
 * main - displays the information contained in
 * the ELF header at the start of an ELF file.
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with status code 98 on failure
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, i;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: can't open file %s\n", argv[1]), exit(98);
	header = malloc(sizeof(Elf64_Ehdr));
	if (!header)
		dprintf(STDERR_FILENO, "Error: malloc fail\n"), exit(98);
	if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n",
						argv[1]), exit(98);

	if (header->e_ident[0] != 0x7f || header->e_ident[1] != 'E' ||
		header->e_ident[2] != 'L' || header->e_ident[3] != 'F')
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]), exit(98);

	printf("ELF Header:\n  Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
		printf(" %02x", header->e_ident[i]);
	printf("\n");
	printClass(header);
	printData(header);
	printf("  Version:                           %d%s",
				header->e_ident[6], header->e_ident[6] == EV_CURRENT ?
				" (current)\n" : "\n");
	printOS(header);
	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printType(header);
	printEntry(header);
	if (close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: can't close %s\n", argv[1]), exit(98);
	free(header);
	return (0);
}
