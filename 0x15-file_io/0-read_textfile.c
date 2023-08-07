#include "main.h"

/**
 * read_textfile - reads a text file and prints
 * it to the POSIX standard output.
 *
 * @filename: name of the file to read
 * @letters:  number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buff;
	ssize_t rBytes, wBytes;

	if (!filename || !letters)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (!buff)
		return (0);

	rBytes = read(fd, buff, letters);
	if (rBytes == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}

	wBytes = write(STDOUT_FILENO, buff, rBytes);
	if (wBytes == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}

	free(buff);
	close(fd);
	if (wBytes != rBytes)
		return (0);

	return (wBytes);
}
