#include "main.h"

/**
 * find_path - handle the path
 * @args: the argument
 *
 * Return: the path
 */

char *find_path(char *argument)
{
}

/**
 * is_exec - check if a path is an executable
 *@path: the path to check
 * Return: 1 if it's executable 0 if not
 */
int is_exec(char *path)
{
     struct stat state;
     if (path == NULL || stat(path, &state) < 0)
	     return 0;
     if (state.st_mode & S_IXUSR)
	     return (1);
}
