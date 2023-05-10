#include "main.h"

/**
 * execmd - search and execute commands received from stdin
 * @argv: a double pointer to arguments to be passed
 * Return: nothing
 */
void execmd(char **argv)
{
	pid_t pidChild; /* hold process ID of child */
	int r = 0, status, wait_error = 0; /* hold return value of child */
	char *cmd = NULL, *envp[] = {NULL}; /* empty env variables for new process */

	if (argv)
	{
		cmd = find_path(argv[0]);/* find the command path */
		if (cmd == NULL)
			_printf("%s: No such file / dir exists\n", argv[0]);
		else
		{
			pidChild = fork(); /* create child process */
			if (pidChild < 0) /* on failure */
			{
				perror("Error: fork failure"); /*print error*/
				exit(EXIT_FAILURE);
			}
			else if (pidChild == 0) /* child process */
			{
				r = execve(cmd, argv, envp);
				free(cmd);
				cmd = NULL;
				if (r < 0) /* execute command */
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait_error = wait(&status);/*wait for child*/
				if (wait_error < 0)
					free_before_exit(argv);
				free_argv(argv);
			}
		}
	}
	free(cmd);
	cmd = NULL;
}

