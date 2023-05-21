#include "main.h"
/**
 * execute_action - executes action
 *@action: the action to execute
 * Return: 0 to exit or 1
 */
int execute_action(_action action)
{
	pid_t childpid, my_pid;
	int status;

	childpid = fork();
	if (childpid == -1) /* if forking fails */
	{
		perror("Error:");
		return (1);
	}
	else if (childpid == 0) /* in the child process */
	{
		if (execve(argv[0], action->args, NULL) == -1)
			perror("Error:");
	}
	else
	{
		wait(&status); /* or waitpid(childpid, &status, 0) */
	}
	return (0);
}

	/*char *environ[]={"home=/","git=","PATH=/home:bin/"};
	pid_t child_pid = fork();
	if (child_pid == 0)
	{
		/*child process*/
