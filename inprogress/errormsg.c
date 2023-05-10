#include "main.h"

/**
 * _error_msg - prints error messahe
 * @name: The name of the shell.
 * @prompt_i: Number of prompt_i.
 * @LinePtr_copy: The pointer to tokenized LinePtr_copy.
 * Return: Nothing.
 */

void _error_msg(char *name, size_t prompt_i, char **LinePtr_copy)
{
	char c;

	c = prompt_i + '0';
	write(1, name, _strlen(name));
	_puts(": ");
	write(1, &c, 1);
	_puts(": ");
	write(1, LinePtr_copy[0], _strlen(LinePtr_copy[0]));
	_puts(": not found\n");
}
