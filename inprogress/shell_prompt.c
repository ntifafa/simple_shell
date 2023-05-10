#include "main.h"

/**
 * _shell_prompt - prints the prompt
 * Return: Nothing.
 */

void _shell_prompt(void)
{
	if (isatty(0))
		write(1, "RN_SHELL $ ", 11);
}
