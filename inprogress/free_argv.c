#include "main.h"

/**
 * _free_argv - frees all memory allocated for LinePtr_copy.
 * @LinePtr_copy: copy of input string
 * Return: Nothing.
 */

void _free_argv(char **LinePtr_copy)
{
	size_t j = 0;

	if (LinePtr_copy == NULL)
		return;

	/*while (LinePtr_copy[j])*/
	/*{*/
		/*free(LinePtr_copy[j]);*/
		/*j++*/
	/*}*/

	if (LinePtr_copy[j] == NULL)
	{
		free(LinePtr_copy[j]);
	}

	free(LinePtr_copy);
}
