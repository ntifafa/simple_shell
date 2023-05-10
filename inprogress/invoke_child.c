#include "main.h"

/**
 * _invok_child - makes child process
 * @LinePtr_copy: The pointer to tokenized LinePtr_copy.
 * @name: The shell's name.
 * @env: Array of enviromental variables.
 * @prompt_i: Prompt count.
 * Return: Nothing.
 */

void _invok_child(char **LinePtr_copy, char *name, char **env, size_t prompt_i)
{
	pid_t pid;
	int status = 0, wait_err = 0;

	(void)wait_err; (void)name; (void)env; (void)prompt_i;
	pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /*child process*/
            _execmd(LinePtr_copy, name, env, prompt_i);
        } else {
            /*parent process*/
            waitpid(pid, &status, 0); /*wait for child process to finish*/
		
		_free_argv(LinePtr_copy);
	}
}
