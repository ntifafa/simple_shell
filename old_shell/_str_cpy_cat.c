#include "main.h"

/**
 * _str_cpy_cat - copies and concatenates to a string
 * @argv0: a string for the command
 * @fullpath: fullpath of command
 * @pathtok: tokenized path
 * Return:
 */

void _str_cpy_cat(char *fullpath, char *pathtok, char *argv0)
{
	/* str = alloc_4_fullpath(pathtok, fullpath, argv0); */
	_strcpy(fullpath, pathtok);
	_strcat(fullpath, "/");
	_strcat(fullpath, argv0);
	/* *fullpath = _strcat(*fullpath, "\0"); */

}
