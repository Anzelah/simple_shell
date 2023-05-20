#include "main.h"
/**
 * execute_action - executes action
 *@action: the action to execute
 * Return: 0 to exit or 1
 */
int execute_action(_action action)
{
	char *environ[]={"home=/","git=","PATH=/home:bin/"};
	pid_t child_pid = fork();
	if (child_pid == 0)
	{
		/*child process*/
		execve(, action->args, envion);
		_printf("error");
	}
	else
	{
		/*main process*/
	}
	return (0);
}
