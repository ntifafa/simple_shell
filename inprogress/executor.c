#include "main.h"

/**
 * _execmd - A function that executes a LinePtr_copy.
 * @LinePtr_copy: The pointer to tokenized LinePtr_copy.
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * @prompt_i: Number of executed prompt_i.
 * Return: Nothing.
 */

void _execmd(char **LinePtr_copy, char *name, char **env, size_t prompt_i)
{
	char **pathvar = NULL, *fullcmdpath = NULL;
	struct stat buf;
	unsigned int i = 0;

	/* if (_strcmp(LinePtr_copy[0], "env") == 0)*/
	/* 	_envir_print(env);*/
	if (stat(LinePtr_copy[0], &buf) == 0)
	{
		if (execve(LinePtr_copy[0], LinePtr_copy, NULL) == -1) {
                perror("execve"); /*execve only returns if there is an error*/
				_free_before_exit(LinePtr_copy);
                exit(EXIT_FAILURE);
		}
	}
	else
	{
		pathvar = _get_pathtok(env);
		while (pathvar[i])
		{
			fullcmdpath = _strcat_sp(pathvar[i], LinePtr_copy[0]);
			i++;
			if (stat(fullcmdpath, &buf) == 0)
			{
				if (execve(fullcmdpath, LinePtr_copy, NULL) == -1)
				{
					perror(name);
					_free_argv(pathvar);
					_free_before_exit(LinePtr_copy);
					exit(EXIT_FAILURE);
				}
				return;
			}
		}
		_error_msg(name, prompt_i, LinePtr_copy);
		_free_argv(pathvar);
	}
}
