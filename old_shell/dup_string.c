#include "main.h"

/**
 * dup_string - frees allocated memory
 *
 * @ustring: - user input string
 * @num_read: number of characters read
 * Return:
 */

char * dup_string(char *ustring, ssize_t num_read)
{
	char *ustring_copy;

	ustring_copy = malloc(sizeof(char) * num_read + 1);
	if (ustring_copy == NULL)
	{
		perror("memory allocation failed");
		return (NULL);
	}
	/* copy ustring to ustring_copy */
	_strcpy(ustring_copy, ustring);

	return (ustring_copy);
}
