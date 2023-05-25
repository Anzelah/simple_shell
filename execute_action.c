#include "main.h"

/**
 * execute_action - executes action
 *@action: the action to execute
 * Return: 0 to exit or 1
 */
int execute_action(char **action)
{
	pid_t childpid;
	int status, i;
	char *path = NULL;

printf("execute_action\n");
for (i = 0; action[i] != NULL; i++){
	printf("argv[%d] =%s\n", i, action[i]);
}
	if (_strcmp(action[0], "exit") == 0)
		return (0);
	if (_strcmp(action[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		_printf(environ[i]), _printf("\n");
		return (1);
	}
	path = find_path(action[0]);
	if (path == NULL)
	{
		perror(action[0]);
		/*_printe(": command not found\n");*/
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
			perror("Error:");
			exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status); /* or waitpid(childpid, &status, 0) */
		free(path);
	}
	return (1); /* don't have to handle environment */
}
