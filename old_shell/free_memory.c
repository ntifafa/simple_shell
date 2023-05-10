#include "main.h"

/**
 * free_memory - frees allocated memory
 *
 * @argv: - array of strings
 * @linePtr: String to be parsed
 * @linePtr_copy: Copy of string to be parsed
 * @counterT: number of tokens
 * Return:
 */

void free_memory(char **argv, char *linePtr, char *linePtr_copy)
{
	size_t i;

	for (i = 0; argv[i] ; i++)
	{
		free(argv[i]);
	}
	free(argv[i]);
	/* if (s != NULL) */
		/* free(s); */
	if (argv != NULL)
		free(argv);
	argv = NULL;
	if (linePtr_copy != NULL)
		free(linePtr_copy);
	linePtr_copy = NULL;
	if (linePtr != NULL)
		free(linePtr);
	linePtr = NULL;

}
