#include "main.h"

/**
 * _get_pathtok - Gets the full value from the
 * PATH enviromental variable.
 * @env: Array of enviromental variables.
 * Return: the directories listed in the
 * PATH environment variable.
 */

char **_get_pathtok(char **env)
{
	char *pathvalue = NULL, **pathvar = NULL;
	size_t k = 0;

	pathvalue = strtok(env[k], "=");
	while (env[k])
	{
		if (strcmp(pathvalue, "PATH") == 0)
		{
			pathvalue = strtok(NULL, "\n");
			pathvar = _parse_token(pathvalue, ":");
			return (pathvar);
		}
		k++;
		pathvalue = strtok(env[k], "=");
	}
	return (NULL);
}
