#include "main.h"

/**
 * _strdup - duplicates a string and saves
 * to a newly allocated space in memory.
 *
 * @str: - string
 *Return: pointer to new space in memory
 */

char *_strdup(char *str)
{
	char *ptr;
	int i;

	if (str == NULL)
		return (NULL);
	ptr = (char *)malloc(_strlen(str) * sizeof(char) + 1);
	if (ptr == NULL)
	{
		_puts("Memory allocation failed\n");
		return (NULL);
	}
	for (i = 0; i < _strlen(str); i++)
		ptr[i] = str[i];

	ptr[i] = '\0'; /* add null terminator */
	return (ptr);
}
