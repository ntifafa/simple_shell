#include "main.h"

/**
 * _parse_token - A function that split and create a full string command.
 * @delimit: The delimiter for str.
 * @LinePtr: The pointer to input string.
 * Return: A string with full command.
 */

char **_parse_token(char *LinePtr, char *delimit)
{
	char *token = NULL, **LinePtr_copy = NULL;
	size_t tokcount = 0;
	int i = 0;

	if (LinePtr == NULL)
		return (NULL);

	/* buffersize = _strlen(LinePtr); */
	/*tokcount = count_tokens(LinePtr, delimit);*/
	while (*(LinePtr + i) != '\0')
		{
			if (LinePtr[i] != ' ' && (LinePtr[i + 1] == ' ' || 
			LinePtr[i + 1] == '\0'))
				tokcount++;
			i++;
		}

	LinePtr_copy = malloc(sizeof(char *) * (tokcount + 1));
	if (LinePtr_copy == NULL)
	{
		perror("Unable to allocate LinePtr");
		free(LinePtr);
		_free_argv(LinePtr_copy);
		exit(EXIT_FAILURE);
	}
	token = strtok(LinePtr, delimit);
	i = 0;
	while (token != NULL)
	{
		LinePtr_copy[i] = malloc(_strlen(token) + 1);
		if (LinePtr_copy[i] == NULL)
		{
			perror("Unable to allocate LinePtr");
			_free_argv(LinePtr_copy);
			free(LinePtr);
			return (NULL);
		}
		LinePtr_copy[i] = token;
		token = strtok(NULL, delimit);
		i++;
	}
	LinePtr_copy[i] = NULL;
	free(LinePtr);
	LinePtr = NULL;
	return (LinePtr_copy);
}
