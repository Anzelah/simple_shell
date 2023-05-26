#include "main.h"


void builtin_cd(char **args)
{
	char *home;
	if (!args[1])
	{
		home = _getenv("HOME");
		if (home)
			chdir(home);
		else
			perror("");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("");
			return;
		}
		setenv("PWD", args[1], 1);
	}
}
