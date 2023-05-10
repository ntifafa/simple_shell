#include "main.h"

/**
 * cdfunctionality - allows the shell to change directory
 * @argv: command line arguments
 *
 * Return:
 **/

void cdfunctionality(char **argv)
{
	if (_strcmp(argv[0], "cd") == 0)
	{
		/*change the current directory if argv[0] is "cd" */
		char *new_dir, *current_dir;

		if (argv[1] == NULL || _strcmp(argv[1], "~") == 0)
			new_dir = getenv("HOME");
		else if (_strcmp(argv[1], "-") == 0)
			new_dir = getenv("OLDPWD");
		else
			new_dir = argv[1];

		if (chdir(new_dir) != 0)
			perror("Error changing directory\n");
		else
		{
			current_dir = getcwd(NULL, 0);
			setenv("OLDPWD", getenv("PWD"), 1);
			setenv("PWD", current_dir, 1);
			if (current_dir != NULL)
				free(current_dir);
		}
	}
}
