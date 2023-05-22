#include "main.h"

/**
 * find_path - handle the path
 * @args: the argument
 *
 * Return: the path
 */

char *find_path(char *argument)
{
	char *envpath = getenv("PATH");
	if (!envpath || _strlen(envpath) == 0)
	     return NULL;
	char buff[1024];
	int i = 0, j;
	while (envpath[i] != '\0')
	{
		j = 0;
		for (; envpath[i] != '\0' && envpath[i] != ':'; i++, j++)
			buff[j] = envpath[i];
		buff[j] = '\0';
		printf("searching %s in #%s#\n", argument, buff);
		if (envpath[i] == '\0')
			break;
		i++; /*skiping : character*/
	}

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
