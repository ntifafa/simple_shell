#include "main.h"

/**
 * _envir_print - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 * Return:
 */

void _envir_print(char **env)
{
	size_t l = 0, len = 0;

	while (env[l])
	{
		len = _strlen(env[l]);

		write(1, env[l], len);
		write(1, "\n", 1);

		l++;
	}
}
