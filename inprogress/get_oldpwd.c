#include "main.h"

/**
 * _get_oldpwd - Gets the value of the
 * OLDPWD enviromental variable.
 * @env: Array of enviromental variables.
 * Return: OLDPWD path
 */

char *_get_oldpwd(char **env)
{
	char *home = NULL;
	size_t i = 0;

	while (env[i])
	{
		if (strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			home = &env[i][7];
			break;
		}
		i++;
	}

	return (home);
}
