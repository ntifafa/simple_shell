#include "main.h"

/**
 * _get_home_dir - Gets the value of the
 * HOME enviromental variable.
 * @env: Array of enviromental variables.
 * Return: the path of the home dir
 */

char *_get_home_dir(char **env)
{
	char *home = NULL;
	size_t i = 0;

	while (env[i])
	{
		if (strncmp(env[i], "HOME=", 5) == 0)
		{
			home = &env[i][5];
			break;
		}
		i++;
	}

	return (home);
}
