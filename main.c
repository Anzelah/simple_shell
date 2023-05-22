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
	int input, i, j;
	char buff[1024], c[2];

	if (argc > 1)
	{
		input = open(argv[1], O_RDONLY);
	}
	while (1)
	{
		_printf("#cisfun$ ");
		if (argc == 1)
		{
			r_getline = getline(&line, &len, stdin);
			for (j = 0; line[j] != '\0' && line[j] != '\n'; j++)
				line[j] = '\0';
		}
		else
			r_getline = getlinefromfile(&line, &len, input);
		if (r_getline == -1)
			break;
		parsed_input = parse_input(line);
		free(line);
		action = interpret_input(parsed_input);
		for (i = 0; action->args[i] != NULL; i++) /* testing action */
		{
			printf("args[%d] = %s\n", i, action->args[i]);
		}
		free_tokens(parsed_input);
		if (!execute_action(action))
		{
			free_action(action);
			break;
		}
	}
	return (0);
}
