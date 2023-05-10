#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, n, newlen;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	newlen = i + j;

	for (n = i; n < newlen; n++)
		dest[n] = *src++;

	/* *src = '\0'; */
	return (dest);
}
