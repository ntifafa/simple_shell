#include "main.h"

/**
 * _strcpy - copies the content of a string
 * @dest: destination string
 * @src: source string
 * Return: a pointer to the new string.
 */

char *_strcpy(char *dest, char *src)
{
	char *p = dest;
	int i = 0;

	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (dest);
}
