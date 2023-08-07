#include "main.h"

/**
 * create_file - creates a file
 *
 * @filename: name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wBytes, text_len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}

	while (text_content[text_len])
		text_len++;

	wBytes = write(fd, text_content, text_len);
	if (wBytes == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
