#include "main.h"

/**
 * main - a simple cloned version of the shell
 * @argc: the number of arguments passed
 * @argv: a double pointer to arguments to be passed
 * Return: 0(success)
*/
int main(int argc, char **argv)
{
	char *ustring = NULL, *ustring_copy = NULL, /* *s = NULL,  */*p = "ls";
	/* size_t ustring_size = 0; */
	ssize_t num_read = 0, tok_count;
	int i = 0;

	(void)argc;
	while (i < 1)
	{
		_puts("$ ");
		fflush(stdout);
		/* num_read = getline(&ustring, &ustring_size, stdin); */
		ustring = strdup(p);
		if (num_read == -1 || num_read == EOF)
			_exit_if_eof(ustring);
		ustring_copy = dup_string(ustring, num_read);
		tok_count = count_tokens(ustring, " \n");
		argv = parse_string(argv, ustring_copy, tok_count);
		if (_strcmp(argv[0], "exit") == 0)
		{
			if ((exit_functionality(argv)) == 0)
				free_before_exit(argv);
			else
				continue;
		}
		execmd(argv); /*execute command*/

		fflush(stdin);
		free_memory(argv, ustring, ustring_copy);
		i++;
	}
	/* free_memory(argv, ustring, ustring_copy); */
	return (0);
}
