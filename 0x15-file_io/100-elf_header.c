#include "main.h"
#include <elf.h>

/**
 * printClass - prints the class from an elf header
 *
 * @header: Elf64_Ehdr struct
 *
 * Return: void
 */
void printClass(Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	if (header->e_ident[4] == 2)
		printf("ELF64\n");
	else if (header->e_ident[4] == 1)
		printf("ELF32\n");
}

/**
 * printData - prints the information about data organization
 * from the elf header
 *
 * @header: Elf64_Ehdr struct
 *
 * Return: void
 */
void printData(Elf64_Ehdr *header)
{
	printf("  Data:                              ");
	if (header->e_ident[5] == 1)
		printf("2's complement, little endian\n");
	else if (header->e_ident[5] == 2)
		printf("2's complement, big endian\n");
}

/**
 * printOS - prints name of the OS
 *
 * @header: Elf64_Ehdr struct
 */
void printOS(Elf64_Ehdr *header)
{
	int i;
	char *names[] = {"UNIX - System V", "UNIX - HP-UX",
					"UNIX - NetBSD", "UNIX - Linux",
					"UNIX - GNU Hurd", "", "UNIX - Solaris",
					"UNIX - AIX", "UNIX - IRIX",
					"UNIX - FreeBSD", "UNIX - Tru64",
					"UNIX - Novell Modesto", "UNIX - OpenBSD",
					"UNIX - Open VMS", "UNIX - NonStop Kernel",
					"UNIX - AROS", "UNIX - Fenix OS",
					"UNIX - CloudABI", "UNIX - OpenVOS"};

	printf("  OS/ABI:                            ");
	for (i = 0; i < 19; i++)
		if (i == header->e_ident[7])
		{
			printf("%s\n", names[i]);
			return;
		}

	printf("<uknown: %d>\n", header->e_ident[7]);

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
	printClass(header);
	printData(header);
	printf("  Version:                           %d (current)\n",
																	header->e_ident[6]);
	printOS(header);
	printf("  ABI Version:                       %d\n", header->e_ident[8]);
	printType(header);
	printf("  Entry point address:               %#lx\n", header->e_entry);
	if (close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: can't close %s\n", argv[1]), exit(98);
	free(header);
	return (0);
}
