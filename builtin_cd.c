#include "main.h"

/**
 * builtin_cd - handle cd
 * @args: arguments
*/
void builtin_cd(char **args)
{
	char *home;
	char temp[1024];

	if (!args[1])
	{
		home = _getenv("HOME");
		if (home)
		{
			if (getcwd(temp, sizeof(temp)) == NULL)
				return;
			setenv("OLDPWD",   temp, 1);
			chdir(home);
		}
		else
			perror("");
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (_getenv("OLDPWD"))
			chdir(_getenv("OLDPWD"));
	}
	else
	{
		if (getcwd(temp, sizeof(temp)) == NULL)
			return;
		setenv("OLDPWD", temp, 1);
		if (chdir(args[1]) != 0)
		{
			perror("");
			return;
		}
		setenv("OLDPWD", temp, 1);
		setenv("PWD", args[1], 1);
	}
}
