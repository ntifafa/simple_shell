#include "main.h"

/**
 * _exit_if_eof - frees allocated memory
 *
 * @argv: - array of strings
 * @linePtr: String to be parsed
 * @linePtr_copy: Copy of string to be parsed
 * @counterT: number of tokens
 * Return:
 */

void _exit_if_eof(char *ustring)
{
	if (ustring != NULL)
	{
		free(ustring);
		ustring = NULL;
	}

	if (isatty(STDIN_FILENO))
	{
		write(1, "\n", 1);
		fflush(stdout);
	}

	exit(EXIT_SUCCESS);
}
