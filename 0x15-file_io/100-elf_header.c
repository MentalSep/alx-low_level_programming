#include "main.h"
#include <elf.h>

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
	if (header->e_ident[0] != 0x7f && header->e_ident[1] != 'E' &&
		header->e_ident[2] != 'L' && header->e_ident[3] != 'F')
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]), exit(98);
	printf("ELF Header:\n  Magic:  ");
	for (i = 0; i < 16; i++)
		printf(" %02x", header->e_ident[i]);
	printf("  Class:                             %s\n",
					header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
					header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
						header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "UNIX - System V");
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
						header->e_type == ET_EXEC ? "EXEC (Executable file)" : "EXEC (Executable file)");
	printf("  Entry point address:               0x%lx (bytes into file)\n", header->e_entry);
	printf("  Start of program headers:          %d (bytes into file)\n", header->e_phoff);
	printf("  Start of section headers:          %d (bytes into file)\n", header->e_shoff);
	printf("  Flags:                             0x%x\n", header->e_flags);
	printf("  Size of this header:               %d (bytes)\n", header->e_ehsize);
	printf("  Size of program headers:           %d (bytes)\n", header->e_phentsize);
	printf("  Number of program headers:         %d\n", header->e_phnum);
	printf("  Size of section headers:           %d (bytes)\n", header->e_shentsize);
	printf("  Number of section headers:         %d\n", header->e_shnum);
	printf("  Section header string table index: %d\n", header->e_shstrndx);
	if (close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: can't close %s\n", argv[1]), exit(98);
	free(header);
	return (0);
}
