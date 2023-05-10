#include "main.h"

/**
 * free_argv - frees memory allocated for argv
 *
 * @argv: - array of strings
 *
 * Return:
 */
void free_argv(char **argv)
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
}
