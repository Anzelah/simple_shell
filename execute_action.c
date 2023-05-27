#include "main.h"

/**
 * _atoi - convert a string to integer
 *@s: the string
 * Return: an integer
 */
int _atoi(char *s)
{
	int len = 0;
	int sign = 1;
	unsigned int result = 0;
	unsigned int ten = 1;
	int otherchar = 0;

	while (s[len] != '\0')
		len++;

	len--;
	while (len >= 0)
	{
		if (s[len] >= '0' && s[len] <= '9')
		{
			if (otherchar && result != 0)
			{
				result = 0;
				ten = 1;
				sign = 1;
			}

			result += (s[len] - '0') * ten;
			ten *= 10;

			otherchar = 0;
		}
		else
			otherchar = 1;
		if (s[len] == '-')
			sign *= -1;
		len--;
	}
	return (sign * result);
}
/**
 * handle_builtin_setenv- builtin
 * @action: action
 * Return: int
 */
int handle_builtin_setenv(char **action)
{
	if (_strcmp(action[0], "setenv") == 0)
	{
		if (action[1] == NULL || action[2] == NULL)
		{
			perror("");
			return (1);
		}
		setenv(action[1], action[2], 1);
		return (1);
	}
	else if (_strcmp(action[0], "unsetenv") == 0)
	{
		if (action[1] == NULL)
		{
			perror("");
			return (1);
		}
		if (unsetenv(action[1]) != 0)
		{
			perror("");
			return (1);
		}
		return (1);
	}
	return (2);
}
/**
 * handle_builtin - builtin
 * @action: action
 * @parsed_input: parsed input
 * Return: int
 */
int handle_builtin(char **action, char **parsed_input)
{
	int i, status;

	if (_strcmp(action[0], "exit") == 0)
	{
		if (action[1] == NULL)
		{
			exit (0);
		}
		else
		{
			
			status = (atoi(action[0]));
			free_tokens(parsed_input);
		}
		exit(status);
	}
	if (_strcmp(action[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			_printf(environ[i]), _printf("\n");
		return (1);
	}

	if (_strcmp(action[0], "cd") == 0)
	{
		builtin_cd(action);
		return (1);
	}
	if (handle_builtin_setenv(action) == 1)
		return (1);
	return (2);
}
/**
 * execute_action - executes action
 *@action: the action to execute
 *@parsed_input: parsed input
 * Return: 0 to exit or 1
 */
int execute_action(char **action, char **parsed_input)
{
	pid_t childpid;
	int status, hb;
	char *path = NULL;

	hb = handle_builtin(action, parsed_input);
	if (hb == 0 || hb == 1)
		return (hb);
	path = find_path(action[0]);
	if (path == NULL)
	{
		free(path);
		return (1);
	}
	childpid = fork();
	if (childpid == -1) /* if forking fails */
	{
		perror("Error:");
		return (1);
	}
	else if (childpid == 0) /* in the child process */
	{
		if (execve(path, action, environ) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status); /* or waitpid(childpid, &status, 0) */
		free(path);
	}
	return (1); /* don't have to handle environment */
}
