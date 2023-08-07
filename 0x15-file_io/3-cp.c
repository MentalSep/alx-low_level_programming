#include "main.h"

/**
 * main - copies the content of a file to another file.
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with different codes on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, rBytes, wBytes;
	char *file_from, *file_to, buff[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	file_from = argv[1];
	file_to = argv[2];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from),
		exit(98);
	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to), exit(99);
	while ((rBytes = read(fd_from, buff, 1024)) > 0)
	{
		wBytes = write(fd_to, buff, rBytes);
		if (wBytes == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to), exit(99);
	}

	if (rBytes == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from),
		exit(98);

	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);

	return (0);
}
