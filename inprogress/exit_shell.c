#include "main.h"

/**
 * _exit_shell - Exits the shell if "exit" is encountered
 * @LinePtr_copy: The pointer to tokenized LinePtr_copy.
 * Return: Nothing.
 */

void _exit_shell(char **LinePtr_copy)
{
	int sta_tus = 0;

	if (LinePtr_copy[1] == NULL)
	{
		_free_argv(LinePtr_copy);
		exit(0);
	}
	else
	{
		perror("Error");
		_free_argv(LinePtr_copy);
		return;
	}

	sta_tus = _atoi(LinePtr_copy[1]);
	_free_argv(LinePtr_copy);
	exit(sta_tus);
}
