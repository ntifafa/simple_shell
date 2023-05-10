#include "main.h"

/**
 * _change_dir_func - changes working directory.
 * @path: The new current working directory.
 * @env: Array of enviromental variables.
 * Return: 0 on success, -1 on failure.
 */

int _change_dir_func(char *path, char **env)
{
	char *new_dir, *current_dir;

	if (path == NULL || _strcmp(path, "~") == 0)
		new_dir = _get_home_dir(env);
	else if (_strcmp(path, "-") == 0)
		new_dir = _get_oldpwd(env);
	else
		new_dir = path;

	if (chdir(new_dir) != 0)
		perror("Error");
	else
	{
		current_dir = getcwd(NULL, 0);
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", current_dir, 1);
		if (current_dir != NULL)
			free(current_dir);
	}
	_free_argv(&path);
	path = NULL;
	return (0);
}
