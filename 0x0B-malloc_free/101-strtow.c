#include "main.h"

/**
 * count_words - counts the number of words in a given string
 *
 * @str: pointer to string
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, Num = 0;

	for (i = 0; str[i]; i++)
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			Num++;

	return (Num);
}
/**
 * get_word - copies a single word from the string
 *
 * @str: pointer to string
 * @start: the start of the word in the string
 * @end: the ned of the word in the string
 *
 * Return: pointer to the word, NULL if it fails
 */
char *get_word(char *str, int start, int end)
{
	char *word;
	int i, len = end - start;

	word = malloc(sizeof(*word) * (len + 1));
	if (!word)
		return (NULL);

	for (i = 0; i < len; i++)
		word[i] = str[start + i];
	word[i] = '\0';

	return (word);

}
/**
 * strtow - splits a string into words
 *
 * @str: string to split
 *
 * Return: a pointer to an array of strings, NULL on failure
 */
char **strtow(char *str)
{
	char **arr;
	int i, j = 0, NumWords, start = 0, end;

	if (!str || !str[0])
		return (NULL);

	NumWords = count_words(str);
	arr = malloc(sizeof(*arr) * (NumWords + 1));
	if (!arr)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			end = i + 1;

			arr[j] = get_word(str, start, end);
			if (!arr[j])
			{
				int i;

				for (i = 0; i < j; i++)
					free(arr[j]);
				free(arr);

				return (NULL);
			}
			j++;
		}
		else if (str[i] == ' ')
			start = i + 1;
	}
	return (arr);
}
