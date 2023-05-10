#include "main.h"

/**
 * find_path - search and execute commands received from stdin
 * @argv0: a string for the command
 * Return: the path of the command
 */

char *find_path(char *argv0)
{
	char *path, *path_cpy, *pathtok, *fullpath = NULL;
	int statval;
	struct stat buf;

	path = getenv("PATH");
	if (path != NULL)
	{
		path_cpy = _strdup(path);
		pathtok = strtok(path_cpy, ":");

		while (pathtok != NULL)
		{
			fullpath = alloc_4_fullpath(pathtok, fullpath, argv0);
			/* _str_cpy_cat(&fullpath, pathtok, argv0); */
			statval = stat(fullpath, &buf);
			if (statval == 0)
			{
				free(path_cpy);
				path_cpy = NULL;
				return (fullpath);
			}
			else
			{
				free(fullpath);
				fullpath = NULL;
				pathtok = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		free(fullpath);
		fullpath = path_cpy = NULL;
		/* check if command itself is a file_path that exists */
		if (stat(argv0, &buf) == 0)
			return (argv0);
		return (NULL);
	}
	return (NULL);
}
