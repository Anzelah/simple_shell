#include "main.h"
/**
 * execute_action - executes action
 *@action: the action to execute
 * Return: 0 to exit or 1
 */
int execute_action(_action *action)
{
	pid_t childpid;
	int status;
	char *path;

	path = find_path(action->cmd_name);

	childpid = fork();
	if (childpid == -1) /* if forking fails */
	{
		perror("Error:");
		return (1);
	}
	else if (childpid == 0) /* in the child process */
	{
		if (execve(path, action->args, NULL) == -1)
			perror("Error:");
	}
	else
	{
		wait(&status); /* or waitpid(childpid, &status, 0) */
	}
	return (0); /* don't have to handle environment */
}
