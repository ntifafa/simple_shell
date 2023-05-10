#include "main.h"

/**
 * exit_functionality - Exits the shell program if argv[0] is "exit"
 * @argv: list of command line arguments
 * Return: If user enters "exit", return the exit status. Otherwise, return 0.
 */

int exit_functionality(char **argv)
{
	if (argv[1] != NULL)
	{
		perror("Too many arguments");
		/* exit_status = atoi(argv[1]); */
		return(EXIT_FAILURE);
	}
	/* exit(exit_status); */
	return (EXIT_SUCCESS);
}
