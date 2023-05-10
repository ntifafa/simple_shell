#include "main.h"

/**
 * main - Entry point
 * Description: A function that creates a simple shell
 * @ac: argument count
 * @av: Array of strings
 * @env: Array of environment variables
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	char *LinePtr = NULL, **LinePtr_copy = NULL;
	ssize_t numchars_read = 0;
	size_t line_size = 0, prompt_i = 0;

	(void)av; (void)ac;
	while (1)
	{
		prompt_i = prompt_i + 1;
		_shell_prompt();
		/*signal(SIGINT, _handle);*/
		numchars_read = getline(&LinePtr, &line_size, stdin);
		if (numchars_read == EOF)
			_EOF_case(LinePtr);
		else if (*LinePtr == '\n')
			free(LinePtr);
		else
		{
			/* LinePtr[_strlen(LinePtr) - 1] = '\0'; */
			LinePtr_copy = _parse_token(LinePtr, " \n\0");
			/*free(LinePtr);*/

			if (_strcmp(LinePtr_copy[0], "exit") == 0)
				_exit_shell(LinePtr_copy);
			else if (_strcmp(LinePtr_copy[0], "cd") == 0)
				_change_dir_func(LinePtr_copy[1], env);
			else
				_invok_child(LinePtr_copy, av[0], env, prompt_i);
		}
		fflush(stdin);
		LinePtr = NULL, LinePtr_copy = NULL, line_size = 0;
	}
	(void)ac;
	return (EXIT_SUCCESS);
}
