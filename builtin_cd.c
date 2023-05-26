#include "main.h"


void builtin_cd(char **args)
{
	if (!args[1])
		chdir(_getenv("HOME"));
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
