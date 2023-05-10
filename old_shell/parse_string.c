#include "main.h"

/**
 * parse_string - tokenizes a string
 * to a newly allocated space in memory.
 *
 * @argv: - array of strings
 * @ustring_copy: String to be parsed
 * @tok_count: number of tokens
 *Return: pointer to an array of strings
 */

char **parse_string(char **argv, char *ustring_copy, int tok_count)
{
	char *token;
	int i;

	/*allocate mem for array of strings*/
	argv = malloc(sizeof(char *) * tok_count + 1);
	if (argv == NULL)
		return (NULL);/*if memory allocaction fails*/
	token = strtok(ustring_copy, " \n");

	for (i = 0; token != NULL; i++)/*traverse array of strings*/
	{
		argv[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (argv[i] == NULL)
		{
			return (NULL); /*if memory allocaction fails*/
			perror("argv[i] failed to allocate");
		}
		_strcpy(argv[i], token); /*cp token into each index*/
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL; /* set last value to NULL to terminate string */
	if (token != NULL)
		free(token);
	/*argv[i] = NULL;*/
	return (argv);
}
