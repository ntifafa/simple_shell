#include "main.h"

/**
 * alloc_4_fullpath - allocates space for the
 * command's full path
 * @pathtok: path token from tokenization
 * @fullpath: absolute path for command
 * @argv0: command token
 * Return: a pointer to the fullpath created.
 */

char *alloc_4_fullpath(char *pathtok, char *fullpath, char *argv0)
{
	int i, j = 0, cmdlen, pathlen;

	cmdlen = _strlen(argv0);
	pathlen = _strlen(pathtok);
	fullpath = malloc(pathlen + cmdlen + 2);
	if (fullpath == NULL)
	{
		_puts("Memory allocation failed\n");
		return (NULL);
	}
	for (i = 0; i < pathlen; i++)
		fullpath[i] = pathtok[i];

	fullpath[i] = '/';
	i++;
	while (argv0[j] != '\0')
	{
		fullpath[i] = argv0[j];
		i++;
		j++;
	}
	fullpath[i] = '\0';
	/* puts(fullpath); */
	/* puts("\n"); */
	return (fullpath);
}
