#include "main.h"
#include <elf.h>

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
 * printEnry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
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
	for (i = 0; i < 16; i++)
		printf(" %02x", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n", header->e_ident[4] ==
				ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n", header->e_ident[5] ==
				ELFDATA2MSB ? "2's complement, big endian" :
				"2's complement, little endian");
	printf("  Version:                           %d%s",
				header->e_ident[6], header->e_ident[6] == EV_CURRENT ?
				" (current)\n" : "\n");
	printOS(header);
	printf("  ABI Version:                       %d\n", header->e_ident[8]);
	printType(header);
	printEntry(header);
	if (close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: can't close %s\n", argv[1]), exit(98);
	free(header);
	return (0);
}
