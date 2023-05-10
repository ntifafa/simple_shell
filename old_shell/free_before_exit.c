#include "main.h"

/**
 * free_before_exit - frees allocated memory before exiting
 *
 * @argv: - array of strings
 *
 * Return:
 */
void free_before_exit(char **argv)
{
	size_t i = 0;

	if (argv == NULL)
		return;

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}

	if (argv[i] == NULL)
	{
		free(argv[i]);
		argv[i] = NULL;
	}

	free(argv);
	argv = NULL;
	exit(EXIT_SUCCESS);
}
