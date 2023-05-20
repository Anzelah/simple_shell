#include "main.h"

/**
 * main - entry point
 *@argc: arguments count
 *@argv: arguments vectors
 * Return: int
 */
int main(int argc, char **argv)
{
	size_t len = 0;
	char *line = NULL;
	ssize_t r_getline = 0;
	char **parsed_input;
	_action *action;
	int i;

	while (1)
	{
		_printf("#cisfun$ ");
		r_getline = getline(&line, &len, stdin);
		if (r_getline == -1)
			break;
		parsed_input = parse_input(line);
		free(line);
		action = interpret_input(parsed_input);
		/* testing action */
		for (i = 0; action->args[i] != NULL; i++)
		{
			printf("args[%d] = %s\n", i, action->args[i]);
		}
		free_tokens(parsed_input);
		if (!execute_action(*action))
			break;
	}
	return (0);
}
